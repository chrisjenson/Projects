#Brian Worts and Chris Jenson
#ELC 463, Computer Engineering Lab II
#Lab 1, Cache Simulator

import math

#def doCache(K, sets, repo):
def doCache(K, KN, repo, dataSet, iteration):


    numSets = int(KN/K)

    cache = [ [ None for i in range(K) ] for j in range(numSets) ]
     
    setHitIndex = 0 
    setToWrite = 0
    misscount = 0
    LRUSetReplacePointer = 0
    LRUReplacementIndexList = []
    refCount = 0
    
    #For every word
    for entry in range(0, len(dataSet)-3, 3):
        word = []               # List containing all references
        refCount += 1

        reference = str(bin((dataSet[entry+2]<<16) | (dataSet[entry+1]<<8) | (dataSet[entry])))
        reference = reference[2:].zfill(24)
        word.append(reference)

        #Seperate the reference into tag and index, can ignore offset
        indexSize = (int)(math.log(K, 2))
        tag = reference[0:(21-indexSize)]    # slice out the offset
        index = reference[(21-indexSize):(21)] # slice out the index
        ##############################
        ## LOOK FOR HIT IN CACHE
        hit = False
        for set in cache:
            if (set[int(index, 2)] == tag):
                hit = True
                setHitIndex = cache.index(set)

        ##############################
        #HIT
        if (hit):
            
            #If FIFO, do nothing

            #If LRU, do stuff
            if (repo == 'LRU'):
            # get the replacement index of the hit                         
                temp = LRUReplacementIndexList[setHitIndex]
                
                # for all priorities greater than the hit, subtract them by 1
                for index in range(len(LRUReplacementIndexList)):
                    if(LRUReplacementIndexList[index] > temp):
                        LRUReplacementIndexList[index] -= 1
                
                # give the MRU the lowest replacement priority
                LRUReplacementIndexList[setHitIndex] = len(LRUReplacementIndexList)-1
                

        ##############################
        #MISS
        else: 
            #increment misscount
            misscount += 1 

            if(repo == 'FIFO'):

                cache[setToWrite][int(index, 2)]  = tag #Replace in settowrite at index
                setToWrite += 1 
                
                if(setToWrite == numSets):
                    setToWrite = 0

            elif (repo == 'LRU'):
                
                 # miss and LRUReplacementIndexList not full:
                if(len(LRUReplacementIndexList) < numSets):
                    #update the priority list
                    LRUReplacementIndexList.append(LRUSetReplacePointer)

                    #add the word to the cache
                    cache[LRUSetReplacePointer][int(index, 2)]  = tag #Replace in settowrite at index
                    LRUSetReplacePointer += 1    

                # cache is full and we have a miss
                else:
                    #find the least recently uses (0) and replace word there
                    writeLocation = LRUReplacementIndexList.index(0)
                    cache[writeLocation][int(index, 2)] = tag

                    # decrement all priorities by 1
                    for index in range(len(LRUReplacementIndexList)):
                        LRUReplacementIndexList[index] -= 1
                    
                    # make the priority of the MRU the highest value
                    LRUReplacementIndexList[writeLocation] = len(LRUReplacementIndexList)-1

            else:
                print('BAD RE-PO') 

    #Calculate the missrate and print the test results
    missRate = (misscount/(refCount*10))*100
    formatted_rate = "{:.4f}".format(missRate)
    print(str(iteration) + ': Replacement Policy = ' + repo + '; KN = ' + str(K*numSets) + '; K = ' + str(K) + '; sets(N) = ' + str(numSets) + '; MISS RATE = ' + str(formatted_rate) + "%" + '; MISS COUNT = ' + str(misscount))   
    print(refCount)

# File Read In
f1 = open('TRACE1.DAT', 'rb')    # Open the trace file
data1 = f1.read()     # Read the file into date
f1.close()

f2 = open('TRACE2.DAT', 'rb')    # Open the trace file
data2 = f2.read()     # Read the file into date
f2.close()

# Parameters
L = 8                   # Number of bytes per line of cache memory
K = [2, 4, 8, 16]       # Number of lines per set
KN = [64, 256]          # Number of sets
Repo = ['FIFO','LRU']   # Replacement Policy

sets = [4, 8, 16, 32]   # Number of sets in the cache
way = 1                 # Set as a 1-way associative cache
apl = 8                 # Set as 8 contiguous addresses per line
memRef = 60000          # Number of 3-byte memory references 
refs = 600000           # Total number of references
iteration = 1

#Cache tests on TRACE1
for z in Repo:
    for y in KN:
        for x in K:
            doCache(x, y, z, data1, iteration)
            iteration += 1

#Cache tests on TRACE2
for z in Repo:
    for y in KN:
        for x in K:
            doCache(x, y, z, data2, iteration)
            iteration += 1