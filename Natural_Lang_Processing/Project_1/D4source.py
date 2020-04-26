import sys


# Source code building on deliverable D3, but for another machine

# helper function that grabs the next state given the current state and symbol
def trans_table(table, curr_state, symbol):
    tableLen = len(table)

    for a in range(tableLen):
        if table[a][0] == curr_state and lineList[a][1] == symbol:
            return lineList[a][2]


# function to recognize a deterministic FSA
def D_recognize(user_string, machine):
    # set the initial conditions
    index = 0
    fileStartState = open("startState_D4.txt")
    curr_state = fileStartState.readline().rstrip('\n')

    # get the final state
    file1 = open("finalStates_D4.txt")
    final_state = file1.readline().rstrip('\n')
    file1.close()

    stringLen = len(user_string)

    # for every char in the tape
    # run extra time to see if newest state is acceptable
    for x in range(stringLen + 1):

        # if the last char
        if x == stringLen or curr_state == final_state:
            # state is acceptable
            if curr_state == final_state:
                return "accept"
            else:
                return "reject"

        # if not a valid transition, checking for null and non-existance
        elif trans_table(machine, curr_state, user_string[index]) is None or trans_table(machine, curr_state,
                                                                                         user_string[index]) == "NULL":
            index = index + 1
            curr_state = "q0"

        # go to next state
        else:
            curr_state = trans_table(machine, curr_state, user_string[index])
            index = index + 1


print('''*** Deliverable 4: Machine using Different Language ***
The accepted characters of the language are the following:''')
fileAlphabet = open("alphabet_D4.txt")
alphabetString = ""
all_lines_list = fileAlphabet.readlines()
for y in all_lines_list:
    alphabetString = alphabetString + y.strip('\n') + ' '

print(alphabetString.rstrip(' '))
# code to read in tape
tape = input("enter your test string: ")
# tape = sys.argv[1]

# code to read in machine, scrub the input of unwanted symbols, and split for easier access
lineList = [line.rstrip('\n').replace(',', '').replace('"', '').split() for line in open("transitionTable_D4.txt")]

print("result:", D_recognize(tape, lineList))
