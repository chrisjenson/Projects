'''
Author: Luke Zambella
Date: 5-9-2020
CSC470 NLP: Final Exam

Intermediary class that converts documents to their bag-of-words NLP representation
This creates the models for different classifications.
Each directory is considered a classification filled with training data and the processor will create as many classifiers as directories given
For the project's case: there are two training models: trainBefore and trainAfter. There will then be two trainingModel objects that correspond to these two training models
'''
from collections import Counter
from glob import glob
from Article import Article
from TrainingModel import TrainingModel
from os import path
import string


class TextProcessor:
    def __init__(self, dirs = None):
        '''
        Class constructor. Only one of the arguments must be specified. This function assumes all files in a directory are .txt files

        directory -> list of strings pointing to directories of training objects
        '''

        self.__vocabulary = set()
        """Set of unigrams for the entire vocabulary"""

        self.__doc_paths = []
        """list of lists containing directories to objects for classifiers"""

        self.__articles = []
        """List of article objects pertaining to each document loaded"""

        self.__training_models = []
        """List of training model objects that correspond to each directory with the training information"""

        self.__THRESH = 1
        """Cutoff threshold for discarding token in a document"""

        # self.__bag_of_words = Counter()
        """Dict representing a bag of words with frequency"""

        self.directories = dirs

        if (self.directories is not None):
            # Get all the files in each directory and add to __doc_paths
            for directory in self.directories:
                docs = glob(f'{directory}/*.txt')
                self.__doc_paths.append(docs)
        else:
            raise ValueError("Must have a directory.")
    
    def getMyProbsBefore(self):
        probs = {}
        probs = self.__training_models[0].getMyProbs()

        return probs
    
    def getMyProbsAfter(self):
        probs = {}
        probs = self.__training_models[1].getMyProbs()

        return probs

    def loadArticles(self):
        """
        Iterate through each document and create an article object for each one.

        Returns the number of training models if successful, -1 otherwise
        """
        for i, classifier in enumerate(self.__doc_paths):
            # Assumes all directories are relative to where the program is ran, IE ./[directory_name]
            classification_name = self.directories[i].split('./')[1]
            print(classification_name)
            # Bag of words for the model
            bag_of_words = Counter()

            try:
                for document in classifier:                    
                    file = open(file=document, mode='r',encoding="utf-8")
                    text = file.read()
                    # Its faster to not close each file lol
                    #file.close()

                    # Get the bag of words for the document
                    doc_words = self.__tokenize(text)

                    # Add to the classifier's bag_of_words
                    bag_of_words = bag_of_words + doc_words
            except IOError as e:
                print(e)
                return -1
            
            # Update the vocabulary
            self.__vocabulary = self.__vocabulary.union(bag_of_words.keys())
            print(f"Length of current vocab: {len(self.__vocabulary)}")
            # Create a model from all the tokens loaded for that classifier
            model = TrainingModel(classification=classification_name, bag_of_words=bag_of_words)            
            self.__training_models.append(model)
        # Compute probability that the class occurs over each training document
        self.__computeClassProbabilities()

        return len(self.__training_models)

    def __computeClassProbabilities(self):
        # Get count of all documents in each class
        class_count = []
        total_count = 0
        for class_docs in self.__doc_paths:
            class_count.append(len(class_docs))
            total_count += len(class_docs)
        
        # Now compute probabilities
        # That list should correspond to the models
        for index, model in enumerate(self.getTrainingModels()):
            model.class_probability = class_count[index] / total_count


    def smoothDataset(self):
        """
        Smooths all the loaded article objects using laplacian smoothing.
        This should be done after all the files have been loaded
        returns 0 if successful
        """
        for model in self.__training_models:
            model.computeProbabilities(smoothing=True, vocabulary=self.__vocabulary)        
        return 0


    def __preprocessor(self, input = ""):
        """
        returns a normalized version of the given document. The string will be lowercase, with all punctuation removed.
        """
        normalize = input.lower()
        normalize = normalize.translate(normalize.maketrans("","", ".,!?:(){}[]"))
        normalize = normalize.strip()
        return normalize


    def __tokenize(self, input = ""):
        """
        Convert a document to its tokenized form. 
        input -> Text to tokenize

        Returns a bag of words Counter dictionary.
        """

        bag_of_words = Counter()
        tokens = input.split()
        for token in tokens:
            # Normalize the token by removing any whitespace, punctuation, casing, etc
            token_processed = self.__preprocessor(token)
            # Sometimes entire tokens can be stripped
            if len(token_processed) == 0:
                continue

            # Skip if there is already a count, counts get merged at the end
            if token_processed in bag_of_words.keys():
                continue
                
            # Discard if the count isnt more than some threshold
            # If it doesn't exist then set the key to the count
            token_count = tokens.count(token_processed)
            if token_count >= self.__THRESH:
                bag_of_words[token_processed] = token_count
            else:
                continue
        
        return bag_of_words

    def getArticles(self):
        """
        Gets all the articles loaded
        """
        return self.__articles

    def getVocab(self):
        return self.__vocabulary

    def getTrainingModels(self):
        return self.__training_models