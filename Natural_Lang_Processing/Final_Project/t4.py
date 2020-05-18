from TextProcessor import TextProcessor
import math

#find the cross entrophies
def crossEnt(probs):

    return

#MAIN
processor = TextProcessor(dirs=['./trainBefore', './trainAfter'])
num_models = processor.loadArticles()

probsBefore = {}
probsAfter = {}


print(f"Finished loading datasets: {num_models} trained models.")
print("Smoothing dataset")
processor.smoothDataset()
print("Finished smoothing")

probsBefore = processor.getMyProbsBefore()
lenBefore = len(probsBefore)

probsAfter = processor.getMyProbsAfter()
lenAfter = len(probsAfter)

#beforeTrain on beforeTest
crossEntBefore = 0
for uni in probsBefore:
    crossEntBefore += math.log(probsBefore[uni])
crossEntBefore *= -1/lenBefore

print(crossEntBefore)

#beforeTrain on afterTest

#afterTrain on beforeTest
crossEntAfter = 0
for uni in probsAfter:
    crossEntAfter += math.log(probsAfter[uni])
crossEntAfter *= -1/lenAfter

print(crossEntAfter)

#afterTrain on afterTest


