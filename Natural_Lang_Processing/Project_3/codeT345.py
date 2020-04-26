import sys              #for command line arguments
import numpy as np      #to create matrix with zeros

#function to calculate the min edit distance given the original sentence M and candidate sentence C
def calMinEditDistScore(strM, strC):

    strM = strM.split()
    strC = strC.split()

    #determine the size of the matrix then create and fill with zeros 
    sizeM = len(strM)
    sizeC = len(strC)
    matrix = np.zeros((sizeM + 1, sizeC + 1))

    #create the borders
    for x in range(sizeM + 1):
        matrix[x, 0] = x
    for y in range(sizeC + 1):
        matrix[0, y] = y

    #navigate the matrix and fill accordingly: start at 1 stop at size
    for i in range(1, sizeM + 1):
        for j in range(1, sizeC + 1):
            if strM[i-1] == strC[j-1]:    #if the same
                matrix[i, j] = min(
                    matrix[i-1, j] + 1,     #remove, cost 1
                    matrix[i-1, j-1],       #replace, an equal substitution, cost 0
                    matrix[i, j-1] + 1)     #insert, cost 1

            else:
                matrix[i, j] = min(
                    matrix[i-1, j] + 1,     #remove, cost 1
                    matrix[i-1, j-1] + 1,   #replace, and unequal substitution, cost 1
                    matrix[i, j-1] + 1)     #insert, cost 1
    
    editDist = matrix[sizeM, sizeC]

    return (max(1 - editDist/sizeM, 0)), matrix #return the edit distance score

#function to calculate and print a path given a minimum edit distance matrix
def calAlignment(matrix, str1, str2):

    str1 = str1.split()
    str2 = str2.split()

    currX = len(str1)
    currY = len(str2)

    counter = matrix[currX, currY]          #counter is the value of the current cell
    currCost = -1                           #currCost is the cost for the operation done to a cell
    prevX = -1                              #prevX is the x-value of the cell prior to the one represented by currX and currY
    prevY = -1                              #prevY is the y-value of the cell prior to the one represented by currX and currY

    finAlign = []

    #as long as we haven't reached the other corner of the matrix, keep backtracking
    while (currX > 0 or currY > 0):
        if(currX < 0):
            currX = 0
        if(currY < 0):
            currY = 0
        #get the values behind the current cell
        pathA = matrix[currX - 1, currY]
        pathB = matrix[currX, currY - 1]
        pathC = matrix[currX - 1, currY - 1]

        #assign values to prevX and prevY before updating currX and currY
        prevX = currX
        prevY = currY
        #assign counter to the cell with the smallest value, and update currX and currY
        if (pathA < pathB):
            if (pathA < pathC):
                counter = pathA
                currX = currX - 1
            else:
                counter = pathC
                currX = currX - 1
                currY = currY - 1
        else:
            if (pathB < pathC):
                counter = pathB
                currY = currY - 1
            else:
                counter = pathC
                currX = currX - 1
                currY = currY - 1

        #calculate the cost of the operation done on the cell represented by prevX and prevY
        currCost = matrix[prevX, prevY] - matrix[currX, currY]

        #if * needs to be assigned due to an insertion, represent that in the output
        if (prevX == currX):
            finAlign.append("*" + "->" + str2[prevY - 1] + " " + str(currCost))
       
        elif (prevY == currY):
            finAlign.append(str1[prevX - 1] + "->" + "*" + " " + str(currCost))
      
        else:
            finAlign.append(str1[prevX - 1] + "->" + str2[prevY - 1] + " " + str(currCost))

    finAlign.reverse()
    print(finAlign)

#calculates the percent match between the original sentence M and candidate sentence C
def percentMatch(strM, strC):

    strM = strM.split()
    strC = strC.split()

    #gets size of sentence M
    sizeM = len(strM)
    
    #create a set of unigrams for each sentence then get their intersection
    setM = set()
    setC = set()

    for word in strM:
        setM.add(word)
    for word in strC:
        setC.add(word)

    sizeIntersect = len(setM.intersection(setC))

    return sizeIntersect/sizeM

#returns a list of the top ten translation candidates using edit distance score given a source sentence and TMB
def calTopTenEDS(sent, bank):

    candidates = {}
    for candidate in bank:
        candidates[candidate], matrix = calMinEditDistScore(sent, candidate)
    
    sortedCandidates = {k:v for k, v in sorted(candidates.items(), key=lambda item: item[1], reverse=True)}  
    topTen = list(sortedCandidates.keys())[:10]
    for candidate in topTen:
        print("\n", candidate)

        score, matrix = calMinEditDistScore(sent, candidate)
        calAlignment(matrix, sent, candidate)  

#returns a list of the top ten translation candidates using percent match given a source sentence and TMB
def calTopTenPM(sent, bank):

    candidates = {}
    for candidate in bank:
        candidates[candidate] = percentMatch(sent, candidate)
    
    sortedCandidates = {k:v for k, v in sorted(candidates.items(), key=lambda item: item[1], reverse=True)}  
    topTen = list(sortedCandidates.keys())[:10]
    for candidate in topTen:
        print("\n", candidate)

#argv 0 is the file name, 1 is first argument
if(len(sys.argv) > 1):
    str1 = sys.argv[1]
    str2 = sys.argv[2]

    editDistScore, matrix = calMinEditDistScore(str1, str2)
    calAlignment(matrix, str1, str2)
    print ("Edit distance score: ", editDistScore)
    print ("Percent match: ", percentMatch(str1, str2), "\n")

else:
    #open file
    enLines = []
    frLines = []
    f1 = open("EMEA.en-fr.en", encoding="utf8")
    for line in f1:
        enLines.append(line.strip())
    f1.close()

    f2 = open("EMEA.en-fr.fr", encoding="utf8")
    for line in f2:
        frLines.append(line.strip())
    f2.close()

    #randomly get 10000 translations for bank and 5 for testing
    sentIndxArr = np.random.choice(len(enLines), 10005)

    enBank = []
    frBank = []
    for i in range(0, 10000):
        enBank.append(enLines[sentIndxArr[i]])
        frBank.append(frLines[sentIndxArr[i]])

    

    #print source sentence and candidates
    for i in range(0,5):
        sent = enLines[sentIndxArr[10000+i]]

        print(sent)
        print("\n*******TOP TEN EDS CANDIDATES AND ALIGNMENTS*********")
        calTopTenEDS(sent, enBank)
        print("\n**********TOP TEN PERCENT MATCH CANDIDATES***********")
        calTopTenPM(sent, enBank)
        print("\n")