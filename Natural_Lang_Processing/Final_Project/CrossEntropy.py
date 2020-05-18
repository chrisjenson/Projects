'''
Author: Luke Zambella
Date 5/16/20
CSC470 Final Project

Program to compute the cross entropies of training sets against testing sets
This software is hardcoded to only work with the requirements of the project
'''
from TrainingModel import TrainingModel
from TextProcessor import TextProcessor
from math import log2

def __computeCrossEntropy(trainingSet=TrainingModel(), testingSet=TrainingModel()):
    '''
    Compute the cross entropy of a training set agatinst a test set
    Both the training set and testing set are trainingModel objects with only one training classification

    The cross entropy is defined as H(P,Q) = 1/N * SUM(p(x)*log2(q(x_i)), N, i = 1). P is the target distribution (Our trained model) and Q is the approximated distribution (The training set)
    N is the size of the test set, p(x) is the probability of the type in trainingSet and q(x_i) is the probability that the type appears in testingSet. x is the set of types in the test set

    A simpler computation is -1/N * SUM(log2(p_trainingset(W_i)), N, i = 1) where W is the set of types in the test set, N is the count of types in the test set and p_trainingset(W_i) is the probability of W in the training set

    returns the entropy as a float
    '''
    # Get all the types from the test set
    x = testingSet.getTypes()

    # Get probabilities of types for trainingSet
    trainingProbabilities = trainingSet.probabilities
    trainingKeys = list(trainingProbabilities.keys())
    N = len(x)

    # Iterate over all words in the test types and get the probabilities from trainingSet
    log_sum = 0
    for testType in x:
        log_sum += log2(trainingProbabilities[testType])
    entropy = -1 * (1/N) * log_sum
    return float(entropy)
    
if __name__ == '__main__':
    # Create serparate training models for each directory
    # The models are indexed the the textProcessors training model list in the order the directories are appended
    processor = TextProcessor(['./trainBefore', './trainAfter', './testBefore', './testAfter'])
    # processor = TextProcessor(['./trainBefore', './testBefore'])
    processor.loadArticles()
    # Smooth datasets
    processor.smoothDataset()
    
    # delist the trainingModels

    models = processor.getTrainingModels()

    # Compute the probabilities (not done automatically)
    '''
    for model in models:
        model.computeProbabilities(smoothing=False, vocabulary=None)
    '''
    # model_trainBefore = models[0]
    # model_testBefore = models[1]
    model_trainBefore = models[0]
    model_trainAfter = models[1]
    model_testBefore = models[2]
    model_testAfter = models[3]

    # Compute the four entropies
    entropy_trainBefore_testBefore = __computeCrossEntropy(trainingSet=model_trainBefore, testingSet=model_testBefore)
    entropy_trainBefore_testAfter = __computeCrossEntropy(trainingSet=model_trainBefore, testingSet=model_testAfter)
    entropy_trainAfter_testBefore = __computeCrossEntropy(trainingSet=model_trainAfter, testingSet=model_testBefore)
    entropy_trainAfter_testAfter = __computeCrossEntropy(trainingSet=model_trainAfter, testingSet=model_testAfter)
    print(f"Entropy of trainBefore-testBefore: {entropy_trainBefore_testBefore}")
    print(f"Entropy of trainBefore-testAfter: {entropy_trainBefore_testAfter}")
    print(f"Entropy of trainAfter-testBefore: {entropy_trainAfter_testBefore}")
    print(f"Entropy of trainAfter-testAfter: {entropy_trainAfter_testAfter}")
