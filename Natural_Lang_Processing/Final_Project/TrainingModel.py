"""
Author: Luke Zambella
Date: 5/10/2020

Represents a single training model for a classification
This contains the bag of words for a training set for a single classification
The probabilities are smoothed using the vocabulary across ALL training sets. This vocab is not built into the object and is input externally

So, for this project, each of the training sets articles will be loaded and combined as one large dataset for that classification. 
This object represents that dataset and the data contained here will be used to the NBayes classifier to classify the test datasets as either from before or after the given date
"""
from collections import Counter
class TrainingModel:
    """
    Training model object for a single classification
    """

    def __init__(self, classification = "", bag_of_words = Counter()):
        """
        Object constructor
        """

        self.__classification = classification
        """
        What classification this model is trained with
        Comes from the folders name.
        """

        self.__bag_of_words = bag_of_words
        """
        A Bag of words for a training model consists of the unigram and its frequency
        Comes from all unigrams in all the text files in a given folder.
        """

        self.probabilities = {}
        """Probabilities for each token in the bag of words. If smoothed, contains probabilities for tokens not in the bag of words as well"""
        
        self.class_probability = 0
        """Probability that the class occurs over all training sets"""

    def getMyProbs(self):
        return self.probabilities

    def computeProbabilities(self, smoothing = False, vocabulary = []):
        """
        Compute the probabilities for all types in the bag of words.

        smoothing -> whether to use add-one smoothing

        vocabulary -> vocabulary to smooth with, if smoothing true.
        """
        # P*(w) = (count(w) + 1) / (N + V)
        # N => size of dict 
        # V => size of vocab
        # This should be iterated over the vocab because it contains the words needed to add 
        # and the words already loaded into the object
        if smoothing:
            V = len(vocabulary)
            N = len(self.__bag_of_words)

            for unigram in vocabulary:
                token_count = self.__bag_of_words[unigram] if unigram in self.__bag_of_words.keys() else 0
                probability = (token_count + 1) / (N + V)
                self.probabilities[unigram] = probability
        else:
            N = len(self.__bag_of_words)
            for unigram in self.getTypes():
                token_count = self.__bag_of_words[unigram]
                probability = (token_count) / N
                self.probabilities[unigram] = probability

    def getClassification(self):
        return self.__classification

    def getTypes(self):
        '''
        Returns all the types in bag_of_words as a set
        '''
        return set(self.__bag_of_words)