'''
Author: Luke Zambella
Date: 5-9-2020

CSC470: NLP Final Exam


Class representing an article in the bag-of-words form. 
That is, it contains the articles unigrams and their multiplicity.

This class is used mainly for classification tasks and not learning
'''
import datetime

class Article:

    def __init__(self, bagOfWords = {}, id = None, classification = None):
        """
        Initialize an Article object.
        BagOfWords -> The unigrams and their multiplicity.
        """
        self.__unigrams = bagOfWords
        """Dict containing unigrams with their multiplicity"""

        self.__probabilities = {}
        """Dict containing the unigrams with their probabilities from self.__unigrams"""

        self.__article_id = ""
        """The ID of the article"""

        self.__classification = classification
        """What the article has been classified as"""

        if id is not None:
            self.__article_id = id


    def smoothDataset(self, vocabulary = set()):
        '''
        Perform laplacian smoothing on the article's unigrams using the given vocabulary.
        The probabilities are calculated using the unigram smoothing equation.

        Returns 0 if successful, -1 otherwise
        '''
        # P*(w) = (count(w) + 1) / (N + V)
        # N => size of dict 
        # V => size of vocab
        # This should be iterated over the vocab because it contains the words needed to add 
        # and the words already loaded into the object

        V = len(vocabulary)
        N = len(self.__unigrams)

        for unigram in vocabulary:
            token_count = self.__unigrams[unigram] if unigram in self.__unigrams.keys() else 0
            probability = (token_count + 1) / (N + V)
            self.__probabilities[unigram] = probability

    def getUnigrams(self):
        """
        Returns the unigrams as a set
        """
        return set(self.__unigrams.keys())

    def getId(self):
        return self.__article_id

    def getProbabilities(self):
        """
        Returns the probability dictionary
        """
        if (len(self.__probabilities) == 0):
            raise ValueError("Probability table is empty!")
        else:
            return self.__probabilities

    def getClassification(self):
        return self.__classification