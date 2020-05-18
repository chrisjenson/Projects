CSC470 Natural Language Processing - Final Project Report
Authorship Attribution
Chris Jenson, Luke Zambella, and Andrew Conzo


Task: In this project you will gain hands-on experience working in a team to implement text classification systems from scratch.  You will also gain additional hands-on practice applying and continuing to increase your 
foundational corpus processing and language modeling skills.  You will gain experience work-ing  with  another  dataset  that  you  
haven’t  worked  with  yet  this  semester,dealing with the timely topic of COVID-19.  
You will tie together many of the things you’ve learned during the semester in order to:

•extract and prepare the data
•implement naive bayes text classifiers using “bag of words'' representation models,
•compute cross entropies
•work in log space to increase efficiency and avoid numerical underflow
•produce  professional  well  documented  software  deliverables  and  reports.


README File


From a Mac in STEM112:


Process the data for the experiments (T2):

The data-set can be downloaded from https://ai2-semanticscholar-cord-19.s3-us-west-2.amazonaws.com/historical_releases.html
using the 05-01-2020 biorxiv_medrxiv subset (the data-set this program was written and tested with). The corresponding metadata.csv
should be downloaded as well.

The data-set has been updated as of 05-12-2020 and I can no longer find the biorxiv_medrxiv subset on the download page. The full 1GB
one should work in theory, so long as the JSON files are placed in the proper directory.

The data-set's json files must be in the directory `[PROJECT_ROOT]/biorxiv_medrxiv/pdf_json/`

This should be the default relative path from extracting the data-set and it must be placed
in the program's root directory. 
Running the program in a terminal must be done in the root directory of the project to ensure that the 
paths the program uses work correctly (IE running the program executable with the working directory ~/ when it's in ~/project5 may 
have it look for the data-set at ~/biorxiv... instead of ~/project5/biorxiv...)

metadata.csv (or take the file that contains the article's ID and date and rename it to metadata.csv) must be placed in the program root directory as well.
So, metadata.csv should be at ~/project5/metadata.csv

1. Open the terminal
2. Navigate to the location where the “FILE_NAME.tar.gz” file was downloaded
3. Ex. if downloaded to Downloads, enter “cd Downloads”
4. To extract the “FILE_NAME.tar.gz” file, type "tar -zxvf FILE_NAME.tar.gz"
5. Type “FOLDER_NAME” to enter the extracted folder named Project5 containing the Python code
6. Run T2.py using the operating system's Python runtime (version >= 3 required). 
 6.1. The paths should not already contain directories named “trainAfter” or “testAfter” or “trainBefore” or “testBefore”
7. The program will then output the training/testing sets to those directories

NOTE: The $ sign is just a symbol to represent a linux-style command-line prompt.  The user wouldn’t actually type the $ sign.


NOTE: If the specified directories already exist, the program will say that the creation of them failed. The program still runs successfully.








Implement naive bayes text classification and analyze the results (T3):


To run the classification program: simply run python on `Classifier.py` IE `$ python Classifier.py`
This source code was written with and tested on Python 3.8 32-bit and Python 3.6 64-bit. 
This should be done after running the files as described in T2 to ensure the proper directories are created. 
The trainBefore/trainAfter and testBefore/testAfter are hard coded into the program.


The program should take a decent while to fully run (around 1-3 minutes) since it has to load 
at least 4000 articles and process each token in them.


The output is a total count of each classification for each testing directory. 
It is run twice for each test directory. So, for all the articles in testBefore, 
there will be a total count for all the articles identified as trainBefore or trainAfter and the same for testAfter. The names are chosen because they were the names of the directory and to keep the code modular, it uses the directory names for classification.


Cross entropy experiments (T4):

To run the cross entropy tasks, run the `CrossEntropy.py` file with Python after running the program as described in T2.
The program will appear to hang at the beginning but it is running the same training procedures as in T3, so it
will take a while to run. It outputs the entropies of the four given combinations in no particular order.


Individual File Description:


README.txt -> This README file.


authors.txt -> List of authors to be input into the author attribution system.


/trainBefore/ -> Randomly sampled biorxiv_medrxiv training directory (from t2.py).


/testBefore/ -> Randomly sampled biorxiv_medrxiv test directory (from t2.py).


/trainAfter/ -> Randomly sampled biorxiv_medrxiv training directory (from t2.py).


/testAfter/ -> Randomly sampled biorxiv_medrxiv test directory (from t2.py).


t2.py -> Python source file containing code for T2.


Article.py -> Object representing a test article to classify (t3)


TrainingModel.py -> Object representing a probabilistic training model from the training data (t3)


TextProcessor.py -> Object that contains methods for creating training models. This holds the trainingModel objects for each training source (t3)


NBayesClassifier.py -> Class with methods for performing Naive Bayes Classifications using all training models and test articles (t3)


Classifier.py -> Program that trains two models using the trainBefore and trainAfter folders and classifies all documents in testBefore and testAfter (t3). This is the main source file for T3.


D3.txt -> Analysis as described in T3 and T4.

D4.txt -> D4 delivery


References:
[1]  Lucy  Lu  Wang,   Kyle  Lo,   Yoganand  Chandrasekhar,   Russell  Reas,Jiangjiang Yang,  Darrin Eide,  Kathryn Funk,  Rodney Michael Kinney,Ziyang Liu, William. Merrill, Paul Mooney, Dewey A. Murdick, DevvretRishi,  Jerry  Sheehan,  Zhihong  Shen,  Brandon  Stilson,  Alex  D.  Wade,Kuansan Wang, Christopher Wilhelm, Boya Xie, Douglas M. Raymond,Daniel S. Weld, Oren Etzioni, and Sebastian Kohlmeier.  Cord-19:  Thecovid-19 open research dataset.ArXiv, abs/2004.10706, 2020.