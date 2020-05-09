import sys
import random
import os
import re
import string

# Create unigram models with Add-1 smoothing for each known text file
def createUnigrams(trainPath, testPath):
    # 62 unigram language models, each learned with Add-1 smoothing
    # 62 different training files
    # Use set of distinct tokens in the **entire dataset** (all 62 files) as vocab set V
    # Each unigram model differs from each other based on the counts observed in each of the 62 train files
    # Corresponds to one of the 62 authors
    # P^hat(w_i|c) = (count(w_i,c) + 1) / (sum(count(w,c)) + |V|)
    unigram_probabilities = dict()
    V, N, C = findParams(trainPath)
    # Combine vocabulary of training data with that of test data
    V_test, _, training_token_counts = findParams(testPath)
    V = V.union(V_test)
    for file in os.listdir(testPath):
        # set up file name
        filename = os.fsdecode(file)[:-4]

        # set up variables
        word_freq = C[filename]
        total = N[filename]
        vocab = len(V)

        # create unigram probability dictionary for file
        prob_dict = dict()

        # calculate add-1 unigram probabilities and add
        for word in V:
            # Calculate add-1 prob for word
            freq = word_freq[word] if word in word_freq.keys() else 0
            prob = (freq + 1) / (total + vocab)
            # Add prob to dict
            prob_dict[word] = prob

        # add probability dict to unigram probabilty set
        unigram_probabilities[filename] = prob_dict
    print("Unigram probabilities created...")
    return unigram_probabilities, training_token_counts

# findParams - Calculate necessary parameters to find the unigram probability estimates for each file
def findParams(basePath):
    fileCount = 0
    V = set()       # length of vocab (types)
    N = dict()      # length of corpus (tokens)
    C = dict()      # word counts of each file (frequencies)
    print("Calculating unigrams parameters for authors in {}".format(basePath))
    for file in os.listdir(basePath):
        filename = os.fsdecode(file)
        fileCount += 1
        print("{}: {}".format(fileCount,filename))
        N_count = 0         # Holds total amount of tokens found in text file
        C_freq = dict()     # Holds frequencies of each token found in text file
        with open(basePath + filename, "r", encoding="UTF-8") as fsource:
            # Go through each line
            for line in fsource:
                # UNUSED - Possibly preprocess and get rid of punctuation??
                preprocessLine = line.translate(str.maketrans('','',string.punctuation))
                # Open up line to its words
                for word in line.split():
                    # Make all words ubiquitous
                    word = word.lower()
                    # Add word to vocabulary Set
                    V.add(word)
                    # Add to token count
                    N_count += 1
                    # Add word to its known frequency
                    C_freq[word] = C_freq.get(word,0) + 1
        # update N
        N[filename[:-4]] = N_count
        # update C
        C[filename[:-4]] = C_freq
    return V, N, C
