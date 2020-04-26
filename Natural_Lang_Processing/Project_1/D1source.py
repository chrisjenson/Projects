import sys

#Source code implementing basic D-Recognize algorithm as sketched in class

#helper function that grabs the next state given the current state and symbol
def trans_table(table, curr_state, symbol):

    tableLen = len(table)

    for a in range(tableLen):
        if(table[a][0] == curr_state and lineList[a][1] == symbol):
            return (lineList[a][2])

#function to recognize a deterministic FSA
def D_recognize(tape, machine):

    #set the initial conditions
    index = 0
    curr_state = "q0"
    
    #get the final state
    file1 = open("finalStates.txt")
    final_state = file1.readline().rstrip('\n')
    file1.close()

    tapeLen = len(tape)

    #for everry char in the tape
    #run extra time to see if newest state is acceptable
    for x in range(tapeLen + 1):

        #if the last char
        if (x == tapeLen):
            #state is accceptable
            if (curr_state == final_state):
                return "accept"
            else:   
                return "reject"

        #if not a valid transition, checking for null
        elif (trans_table (machine, curr_state, tape[index]) is None):
            return "reject"

        #go to next state
        else:
            curr_state = trans_table (machine, curr_state, tape[index])
            index = index + 1

#code to read in tape
#tape = "baaaa!"
#tape = sys.argv[1]

print('''*** Deliverable 1: Basic D-recognize algorithm ***
The accepted characters of the language are the following:''')
fileAlphabet = open("alphabet.txt")
alphabetString = ""
all_lines_list = fileAlphabet.readlines()
for y in all_lines_list:
    alphabetString = alphabetString + y.strip('\n') + ' '

print(alphabetString.rstrip(' '))
# code to read in tape
tape = input("enter your test string: ")

#code to read in machine, scrub the input of unwanted symbols, and split for easier access
lineList = [line.rstrip('\n').replace(',','').replace('"','').split() for line in open("transitionTable.txt")]

print(D_recognize(tape, lineList))