import sys              #for command line arguments
import numpy as np      #to create matrix with zeros

#function to calculate the min edit distance given two words
def calMinEditDist(word1, word2):

    #determine the size of the matrix then create and fill with zeros 
    sizeX = len(word1) + 1
    sizeY = len(word2) + 1
    matrix = np.zeros((sizeX, sizeY))

    #create the borders
    for x in range(sizeX):
        matrix[x, 0] = x
    for y in range(sizeY):
        matrix[0, y] = y

    #navigate the matrix and fill accordingly: start at 1 stop at size
    for i in range(1, sizeX):
        for j in range(1, sizeY):
            if word1[i-1] == word2[j-1]:    #if the same
                matrix[i, j] = min(
                    matrix[i-1, j] + 1,     #remove, cost 1
                    matrix[i-1, j-1],       #replace, an equal substitution, cost 0
                    matrix[i, j-1] + 1)     #insert, cost 1

            else:
                matrix[i, j] = min(
                    matrix[i-1, j] + 1,     #remove, cost 1
                    matrix[i-1, j-1] + 2,   #replace, and unequal substitution, cost 2
                    matrix[i, j-1] + 1)     #insert, cost 1
    
    #print (matrix)

    calAlignment(matrix, sizeX, sizeY)
    
    return (matrix[sizeX - 1, sizeY - 1]) #print the buttom right value, the min distance

#function to calculate and print a path given a minimum edit distance matrix
def calAlignment(matrix, sizeX, sizeY):
    currX = sizeX - 1                       #currX is the x-value of our current cell
    currY = sizeY - 1                       #currY is the y-value of our current cell
    counter = matrix[currX, currY]          #counter is the value of the current cell
    currCost = -1                           #currCost is the cost for the operation done to a cell
    prevX = -1                              #prevX is the x-value of the cell prior to the one represented by currX and currY
    prevY = -1                              #prevY is the y-value of the cell prior to the one represented by currX and currY

    finAlign = []

    #as long as we haven't reached the other corner of the matrix, keep backtracking
    while (currX > 0 or currY > 0):
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
            finAlign.append("*" + "->" + word2[prevY - 1] + " " + str(currCost))
       
        elif (prevY == currY):
            finAlign.append(word1[prevX - 1] + "->" + "*" + " " + str(currCost))
      
        else:
            finAlign.append(word1[prevX - 1] + "->" + word2[prevY - 1] + " " + str(currCost))

    finAlign.reverse()
    print(finAlign)

#argv 0 is the file name, 1 is first argument
word1 = sys.argv[1]
word2 = sys.argv[2]

# hardcoding words for testing
#word1 = "sunday"
#word2 = "saturday"

#calMinEditDist(word1, word2)
print ("Edit Cost: " + str(calMinEditDist(word1, word2)))