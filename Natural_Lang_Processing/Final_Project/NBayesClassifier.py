'''
Author: Luke Zambella
Date: 5/9/2020

Class file implementing funtions to run naive bayes classification on an articleusing a training model

Let the features be all the tokens in the documents
Get the probability that a class occurrs as well

To calculate Naive Bayes, use this equation: P(test document | current_class)*x*p(current_class).
for p(d|c)*x, find p(x_i | class) for all x_i (token) in the test document that are also in the training models
Compute probability in both the trainBefore and trainAfter models and choose the better one

All probabilistic equations are done in the log space using addition instead of multiplication.

'''
from collections import Counter
from os import path
from Article import Article
from math import log2

class NBayesClassifier:
    def __init__(self, training_models = []):
        """
        Initialize a classifier

        training_models -> list of training model objects that have already been processed
        """
        self.__training_models = training_models


    def classifyDocument(self, document=""):
        """
        Classifies a document against all of the loaded training models

        Document is a path to any text document.

        returns an article object
        """
        # load the document as an article to get all the unigrams and their counts
        with open(file=document, mode='r',encoding="utf-8") as w:
            filepath, filename = path.split(document)       # Want to use the filename as the ID of the article
            article_id = filename.split('.')[0]             # Text files are consistent, there should be no conflicts here
            
            text = w.read()
            doc_words = self.__tokenize(text)

            # Now that we have the tokens and counts for the test document, compute the probabilities for each model.
            probabilities = self.__computeProbabilities(doc_words)
            # Now find the classification with the largest value
            # logs for x < 1 are negative
            index_of_largest = -2147000000
            prob_of_largest = -2147000000
            for index, prob in enumerate(probabilities):
                if prob > prob_of_largest:
                    index_of_largest = index
                    prob_of_largest = prob
            classification = self.__training_models[index_of_largest].getClassification()

            article = Article(bagOfWords=doc_words, id=article_id, classification=classification)
            return article


    def __computeProbabilities(self, bag_of_words=Counter()):
        """
        Computes the probabilities of a classification using the given bag of words

        bag_of_words -> test document bag of words representation

        returns a list of probabilities for each classification in log form IE [class1 = somenumber, class2 = someothernumber]
        """
        # List contains results for each class corresponding to how the training_model is indexed
        res = []
        # Iterate over the training models
        for training_model in self.__training_models:
            # P(c) Probability of class
            class_probability = log2(training_model.class_probability)
            probabilities = training_model.probabilities
            # X
            X = self.__feature_probability(bag_of_words, probabilities)
            # Both are in log form so add them
            p_class = class_probability + X
            res.append(p_class)
        return res


    def __feature_probability(self, doc_tokens={}, class_probabilities = {}):
        """
        finds p(x_i | class). Uses the class_probabilities for each token both share

        doc_tokens -> dictionary (or list) of all the tokens in a test document

        class_probabilities -> dict with each token and its probability in a classification training model. Should be smoothed

        Returns the probability in log form (IE a sum of logs of probabilities)
        """
        doc_set = set(doc_tokens)
        class_set = set(class_probabilities)
        common_unigrams = class_set.intersection(doc_set)
        log_sum = 0
        for token in common_unigrams:
            log_sum += log2(class_probabilities[token])
        return log_sum


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
        dictionary -> existing bag_of_words dictionary. Token counts are added to the existing ones if this is passed

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
                
            # Discard if the count isn't more than some threshold
            # If it doesn't exist then set the key to the count
            token_count = tokens.count(token_processed)
            if token_count >= 1:
                bag_of_words[token_processed] = token_count
            else:
                continue
        
        return bag_of_words