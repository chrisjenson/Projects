import json     # For using the JSON files
import csv      # For using the metadata file
import random   # For random num generation
import os       # For creating the directories

# Function that will extract all of the IDs in the used corpus
def extractIDs():

    IDList = []

    # Go to where the json files are stored
    sourceDir = os.getcwd() + "/biorxiv_medrxiv/pdf_json"
    
    # For each json file get the article ID
    for entry in os.listdir(sourceDir):     
        if (entry.endswith(".json")):   
            ID = entry.split('.')
            IDList.append(ID[0]) 

    # Get the articles sorted by publish date
    IDDates = publishDates(IDList)

    # List of just the keys
    sortedIDs = list(IDDates.keys())

    beforeSet = []
    afterSet = []

    # Split the articles into before and after
    for x in range(len(sortedIDs)):
        if(x < int(len(sortedIDs)/2)):
            beforeSet.append(sortedIDs[x])
        else:
            afterSet.append(sortedIDs[x])

    writeFiles(beforeSet, afterSet)

    return

# Obtain and sort the publish dates
def publishDates(IDList):

    textDate = {}

    # Create a dict of IDS as keys and dates as values
    with open('metadata.csv', encoding="UTF-8") as csvfile:
        readCSV = csv.reader(csvfile, delimiter=',')
        for row in readCSV:
            if(row[1] in IDList):
                textDate[row[1]] = row[9] 
    
    # Sort the entries by date published, oldest first
    sortedDates = dict(sorted(textDate.items(), key = lambda x: x[1]))

    return sortedDates

def writeFiles(beforeSet, afterSet):
    
    # Create random numbers for Before and after
    # The range is 0-number of entries
    # total numbers is 90% of the number of entries 
    randBefore = random.sample(range(len(beforeSet)), int(len(beforeSet)*0.9))
    randAfter = random.sample(range(len(afterSet)), int(len(afterSet)*0.9))

    # Writing the files for the before set
    for x in range(len(beforeSet)):
        fsource = open(os.getcwd() + "/biorxiv_medrxiv/pdf_json/" + beforeSet[x] + ".json",)
        data = json.load(fsource)
        results = data['body_text']
        
        if(x in randBefore):    # If one of the selected traininng files
            fdest = open(("trainBefore" + "/" + beforeSet[x] + ".txt"), "w+", encoding="UTF-8")
            for result in results:      # Iterating through the json and writing the text to a file
                fdest.write(result['text'])

        else:
            fdest = open(("testBefore" + "/" + beforeSet[x] + ".txt"), "w+", encoding="UTF-8")
            for result in results:      # Iterating through the json and writing the text to a file
                fdest.write(result['text'])
        
        fsource.close()
        fdest.close()

    # Writing the files for the after set
    for x in range(len(afterSet)):
        fsource = open(os.getcwd() + "/biorxiv_medrxiv/pdf_json/" + afterSet[x] + ".json",)
        data = json.load(fsource)
        results = data['body_text']
        
        if(x in randAfter):     # If one of the selected traininng files
            fdest = open(("trainAfter" + "/" + afterSet[x] + ".txt"), "w+", encoding="UTF-8")
            for result in results:      # Iterating through the json and writing the text to a file
                fdest.write(result['text'])

        else:
            fdest = open(("testAfter" + "/" + afterSet[x] + ".txt"), "w+", encoding="UTF-8")
            for result in results:      # Iterating through the json and writing the text to a file
                fdest.write(result['text'])
        
        fsource.close()
        fdest.close()
    
    return

# MAIN
# Try creating the directories that will be used for this project
try:
    os.mkdir("trainBefore")
    os.mkdir("trainAfter")
    os.mkdir("testBefore")
    os.mkdir("testAfter")
except OSError:
    print ("Creation of directories failed or they already exist")

extractIDs()