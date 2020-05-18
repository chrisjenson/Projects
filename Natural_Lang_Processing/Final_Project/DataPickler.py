"""
Instead of calculating all those 100k smoothed probabilities for 
each article's unigrams every time the program is ran

Create a pickle file once and load it from subsequent runs
"""
from Article import Article
from TextProcessor import TextProcessor
from os import path
import pickle


dir = "./trainBefore"

processor = TextProcessor(dirs=['./trainBefore', './trainAfter'])
num_models = processor.loadArticles()

print(f"Finished loading datasets: {num_models} trained models.")
print("Smoothing dataset")
processor.smoothDataset()

print("Pickling object")
# Pickle the textprocessor objects
trainBefore_pickle = "training_model.dat"


with open(trainBefore_pickle, "wb") as f:
    pickle.dump(processor, f)
print("Wrote pickle")
