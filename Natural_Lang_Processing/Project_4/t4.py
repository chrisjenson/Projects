import sys
import random
import os
import re
import string
import math
import argparse
from t3 import createUnigrams, findParams

# alltokens - AllTokens authorship attribution system
# unigram_probs: {AuthorID: {word: probability, ...}, ...}
def allTokens(unigram_probs, test_tokens):
    # AllTokens system
    # for test file, compute geometric mean of unigram probs for candidate author for all tokens in test file
    # Compute geometric mean in log space
    # GeometricMean = exp((1/n)*sum(log(p_i)))
    # Use AllTokens to compute score of any of the 62 authors for any of the 62 test sets
    # higher score -> stronger system belief in authorship
    # produce ranking of who suspected authors are in order from most likely -> least likely
    geoMeans = dict()
    for author,unigrams in unigram_probs.items():
        # Find n or total number of unigrams
        n = len(test_tokens)
        # Iterate over all unigrams to find log sum total
        logSum = 0
        for token in unigrams.keys():
            # Filter probabilites added by those in test file
            if token in test_tokens.keys():
                logSum += math.log(unigrams[token])
        # Calculate geometric mean
        geoMean = math.exp((1/n)*logSum)
        # Add geometric mean to dictionary of means per author
        geoMeans[author] = geoMean
    return geoMeans

# singletons - Singletons authorship attribution system
def singletons(unigram_probs, test_tokens):
    # Singleton system
    # for test file, compute geometric mean of unigram probs for candidate author for tokens that occur once in test file
    # Compute geometric mean in log space
    # GeometricMean = exp((1/n)*sum(log(p_i)))
    # produce ranking of who suspected authors are in order from most likely -> least likely
    geoMeans = dict()
    for author,unigrams in unigram_probs.items():
        # Find n or total number of unigrams
        n = 0
        # Iterate over all unigrams to find log sum total
        logSum = 0
        for token in unigrams.keys():
            # Filter probabilites added by those in test file
            if token in test_tokens.keys() and test_tokens[token] == 1:
                logSum += math.log(unigrams[token])
                n += 1
        # Calculate geometric mean
        geoMean = math.exp((1/n)*logSum)
        # Add geometric mean to dictionary of means per author
        geoMeans[author] = geoMean
    return geoMeans

# writeProbs - Use AllTokens or Singletons system to write ranked lists for the scores of several authors
def writeProbs(train_unigram_probs, test_files_token_counts, type, authorList = ["70535", "33913"]):
    type = type.lower()
    # loop through all authors
    for author in authorList:
        if type == "alltokens":
            # Find and sort alltokens probabilities into a list of tuples
            print("Calculating all tokens scores for author {}...".format(author))
            auth_attr = allTokens(train_unigram_probs, test_files_token_counts[author])
        elif type == "singletons":
            # Find and sort singletons probabilities into a list of tuples
            print("Calculating singletons scores for author {}...".format(author))
            auth_attr = singletons(train_unigram_probs, test_files_token_counts[author])

        # Create list of sorted tuples
        sorted_dict = {k: v for k, v in sorted(auth_attr.items(), key=lambda item: item[1], reverse=True)}
        tuple_list = [(k, v) for k, v in sorted_dict.items()]

        # Print results
        print("{}: {}".format(author, type))
        for auth_prob in tuple_list:
            print(auth_prob)

        # Output list to file
        file = open("{}_{}.txt".format(type,author),"w")
        tuple_list = map(lambda x:str(x)+'\n',tuple_list)
        file.writelines(tuple_list)
        file.close()

# Parse arguments
parser = argparse.ArgumentParser()
parser.add_argument("train_dir", help="path to populated training directory")
parser.add_argument("test_dir", help="path to populated testing directory")
parser.add_argument("author_file", help="path to list of authors to gather authorship attribution scores")
args = parser.parse_args()

# Create author list variable
authorList = []
authorPath = args.author_file
with open(authorPath, "r", encoding="UTF-8") as fsource:
    for authorID in fsource:
        authorList.append(authorID.strip())

trainPath = args.train_dir
testPath = args.test_dir
# Create unigram probabilities and token counts for training and test sets
train_unigram_probs, test_files_token_counts = createUnigrams(trainPath, testPath)

# Create ranked lists for probabilities of authors
writeProbs(train_unigram_probs,test_files_token_counts,"alltokens",authorList)
writeProbs(train_unigram_probs,test_files_token_counts,"singletons",authorList)
