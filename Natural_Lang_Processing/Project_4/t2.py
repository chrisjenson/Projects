import sys      # For command line arguments
import random   # For random num generation
import os       # For creating the directories
import argparse

def createDataset(datasetFile,trainPath,testPath):
    print("Creating training and test sets...")

    # Try creating the two directories
    try:
        os.mkdir(trainPath)
        os.mkdir(testPath)
    except OSError:
        print ("Creation of the directory %s failed" % trainPath)
        print ("Creation of the directory %s failed" % testPath)

    # Create the set of 100 unique random numbers between 0-999 inclusive
    # Lists start at index 0 so 0-999 is equilavent to 1-1000
    testNumbers = []
    testNumbers = random.sample(range(1000), 100)
    assert(len(testNumbers) == len(set(testNumbers)))

    # Create the list of line numbers desired in the test directory for each author
    lineNumbers = []
    for x in testNumbers:
        for y in range(62):
            lineNumbers.append(x + (1000 * y))

    authors = []    # List of the author ids
    closingNums = list(range(0, 62000, 1000))   # Where the reviews switch to the next author, for closing the files

    # With block that opens the text file for better handling and management
    #with open(sourcePath, "r", encoding="UTF-8") as fsource:
    with open(datasetFile, "r", encoding="UTF-8") as fsource:
        lineCount = 0   # UUsed to keep count of the current line

        # Go line by line
        for line in fsource:
            temp = line.split("\t", 4)

            # Get all of the authors
            if(temp[1] not in authors):
                authors.append(temp[1])

                # Create the text files in both directories
                # Not using with block to use both files
                ftrain = open(trainPath + "//" + authors[len(authors)-1] + ".txt", "a+", encoding="UTF-8")
                ftest = open(testPath + "//" + authors[len(authors)-1] + ".txt", "a+", encoding="UTF-8")

            # Determine which file to write to and then do so
            if(lineCount in lineNumbers):
                ftest.write(temp[4])

            else:
                ftrain.write(temp[4])

            # Increment the count
            lineCount += 1

            # If moving to the next author, close the files of the previous
            if(lineCount in closingNums):
                ftrain.close()
                ftest.close()

        # Close the last authors files
        ftrain.close()
        ftest.close()
    print("Training ({}) and test ({}) sets created.".format(trainPath,testPath))

# Parse arguments
parser = argparse.ArgumentParser()
parser.add_argument("dataset_file", help="path to dataset file")
parser.add_argument("train_dir", help="path to training directory")
parser.add_argument("test_dir", help="path to testing directory")
args = parser.parse_args()

createDataset(args.dataset_file, args.train_dir, args.test_dir)
