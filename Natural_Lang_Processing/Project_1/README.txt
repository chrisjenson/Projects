Project 1: FSA Recognizer
by Chris Jenson and Yash Dhayal

Task: Implement a recognizer for deterministic finite state automata in the  programming language(s) of your choice, 
as long as all software needed is currently installed on the TCNJ CS systems in the STEM 112 Mac Computers. 
Provide documentation and in particular, a ReadMe file explaining how to run the software from the Mac Terminal command line prompt.

All of the files necessary are present in the one project folder.

Text files:
states.txt - each line contains a string identifying a state of the sheep machine
alphabet.txt - each line contains alphanumeric character of sheep machine
startState.txt - contains the start state of sheep machine
finalStates.txt - contains final state(s) of sheep machine
transitionTable.txt - contains all possible state transitions/paths for the sheep machine

Source code files:
D1source.py - The source code for Deliverable 1
D2source.py - The source code for Deliverable 2
D3source.py - The source code for Deliverable 3
D4source.py - The source code for Deliverable 4. This will use the below txt files, due to needing a different machine

D4 text files:
states_D4.txt - contains the states of Deliverable 4 machine
alphabet_D4.txt - contains the alphabet of Deliverable 4 machine
startState_D4.txt - contains the states of Deliverable 4 machine
finalStates_D4.txt - contains final state(s) of Deliverable 4 machine
transitionTable_D4.txt - contains all possible state transitions/paths for the new machine

How to Run:
- Open the terminal
- Navigate to the location where the CJ_YD_Prj1.tar.gz file was downloaded
    Ex. if downloaded to Downloads, enter "cd Downloads"
- To extract the CJ_YD_Prj1.tar.gz file, type "tar -zxvf CJ_YD_Prj1.tar.gz". 
- Type "cd Project1" to get into the extracted folder named Project1 containing the python code
    NOTE: To run the following scripts, make sure you have python3 installed. Enter "sudo apt-get install python3.6" to install it.
- Type "python3 D?.py", in which you replace '?' with the number corresponding to the deliverable you wish to run, and hit enter
- You will be then prompted to enter a tape of your choosing 
- Type in an input and then press enter. Example inputs for each deliverable are given below
- The program will print either "accept" or "reject" based on the machine and input.

D1:
D1 is the basic algorithm as sketched in class for the sheep language
Valid examples: "baaaa!", "baaaaaaaa!"
Invalid examples: "hhbaaaa!", "baaaa!hh", "baaha!"

D2:
D2 is an expansion on D1 where it still uses the sheep language and accepts characters before the match
Valid examples: "baaaa!", "habaaa!"
Invalid examples: "bahaa!"

D3:
D3 is an expansion on D2 and D3 that uses the sheep language and accepts characters after the match
Valid examples: "baaaa!", "habaaa!", "baaaaa!ha", "hahbaaaaa!hah"
Invalid examples: "bahaa!"

D4 Machine:
The new machine can be described using the regular expression /th[ic]+k/
Some valid examples are: "notthick", "notthiiiicccckbacon", "thicksauce"
Invalid examples are: "thic!k", "thhick", "nothictk"
