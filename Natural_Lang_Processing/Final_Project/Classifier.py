"""
Classify all the test documents
"""

from Article import Article
from TextProcessor import TextProcessor
from os import path
from glob import glob
from NBayesClassifier import NBayesClassifier
from collections import Counter

import pickle

# the test folders are only loaded to add their types to the vocabulary for smoothing
# The program will use them to classify their own documents but the results are disregarded
processor = TextProcessor(dirs=['./trainBefore', './trainAfter', './testBefore', './testAfter'])
num_models = processor.loadArticles()

print(f"Finished loading datasets: {num_models} trained models.")
print("Smoothing dataset")
processor.smoothDataset()
print("Finished smoothing")

print("~~~~~~~~~~~~~~~~~~~~~~~~classifying documents in testAfter~~~~~~~~~~~~~~~~~~~~")
docs = glob('./testAfter/*.txt')

classifier = NBayesClassifier(processor.getTrainingModels())
articles = []
for document in docs:
    article = classifier.classifyDocument(document)
    articles.append(article)
classifications = []

for article in articles:
    classifications.append(article.getClassification())

counts_after = Counter(classifications)
print(counts_after.most_common(4))

print("~~~~~~~~~~~~~~~~classifying documents in testBefore~~~~~~~~~~~~~~~~")
docs = glob('./testbefore/*.txt')
articles = []
for document in docs:
    article = classifier.classifyDocument(document)
    articles.append(article)

classifications = []
for article in articles:
    classifications.append(article.getClassification())

counts_before = Counter(classifications)
print(counts_before.most_common(4))