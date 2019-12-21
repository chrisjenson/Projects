/*==========================================================
 Author: Christopher Jenson
 Modified By: N/A
 Date:        5/9/2018

 Course: CSC-215
 File:  phoneBook.cpp
 Rev #: 2.6
 Description: 1.0- The goal of this program is to create a
 				   functional phone book, a skeleton is in
 				   place.
 			  1.1- Contacts can be added and a list of all
 			  	   contacts can be printed upon request.
 			  1.2- Contacts can be deleted.
 			  2.0- Moved things into seperate functions
 			  	   instead of main.
 			  2.1- Can search for contacts.
 			  2.2- Bug fixes.
 			  2.3- Changed the delete and search function
 			  	   to ask for the first or last name instead.
 			  	   More bug fixes.
 			  2.4- Added more flexibility for user inputs.
 			  2.5- Can have a file be created that stores
 			  	   all your contacts as a text document.
 			  2.6- Can now sort the entries.
 ============================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//function to add contacts
void addContact(vector<string>& first, vector<string>& last, vector<string>& numbers)
{
	//adds the given info into the last position in the vectors
	cout << endl << "Please enter the contacts full name and phone number (ex: John Doe 123456789):" << endl;
	cin >> first.at(first.size() - 1);
	cin >> last.at(last.size() - 1);
	cin >> numbers.at(numbers.size() - 1);

	//increases the size of each vector by one
	first.resize(first.size() + 1);
	last.resize(last.size() + 1);
	numbers.resize(numbers.size() + 1);

	return;
}//end of addContact

//function to delete contacts
void deleteContact(vector<string>& first, vector<string>& last, vector<string>& numbers)
{
	int removeContact;
	int count = 1;
	string searchName;
	string junk;
	bool contactFound = false;

	cout << endl << "Please enter the first or last name of the contact you would like to delete:" << endl;
	cin >> searchName;
	getline(cin , junk);
	cout << endl;

	for(int i = 0; i < (last.size() - 1); ++i)	//runs through each element
	{
		if((last.at(i) == searchName) || (first.at(i) == searchName))	//if the given name matches the element, print that element
		{
			cout << (i + 1) << ": " << first.at(i) << " " << last.at(i) << " " << numbers.at(i) << endl;
			count += 1;
			contactFound = true;
		}//end of if statement
	}//end of for loop

	if(contactFound == false)
	{
		cout << "No contacts found" << endl;
	}
	else	//only want to trigger if a match was found during the for loop
	{
		cout << endl << "Enter the entry number of the contact you would like removed (from above): " << endl;
		cin >> removeContact;
		removeContact -= 1; //subtract one since one was added so the display would start at 1

		//set the position being removed equal to the ones at the end
		//minus 2 because the vectors are resized to include an extra space when a contact is added
		first.at(removeContact) = first.at(first.size() - 2);
		last.at(removeContact) = last.at(last.size() - 2);
		numbers.at(removeContact) = numbers.at(numbers.size() - 2);

		//remove the last element
		first.pop_back();
		last.pop_back();
		numbers.pop_back();
	}//end of else statement

	return;
}//end of deleteContact

//function to display all contacts
void showContacts(vector<string>& first, vector<string>& last, vector<string>& numbers)
{
	cout << endl;
	for(int i = 0; i < (first.size() - 1); ++i)	//runs through the vector printing out each element
	{
		cout << (i + 1) << ": " << first.at(i) << " " << last.at(i) << " " << numbers.at(i) << endl;
	}

	return;
}//end of showContacts

//function to search for contacts given last name, first name
void searchContacts(vector<string>& first, vector<string>& last, vector<string>& numbers)
{
	string searchName;
	string junk;
	bool contactFound = false;

	cout << endl << "Please enter the first or last name of the contact you would like to search for:" << endl;
	cin >> searchName; //will only search for the first input
	getline(cin , junk);
	cout << endl;

	for(int i = 0; i < (last.size()-1); ++i)	//if the given name is present, prints out the contact
	{
		if((last.at(i) == searchName) || (first.at(i) == searchName))
		{
			cout << first.at(i) << " " << last.at(i) << " " << numbers.at(i) << endl;
			contactFound = true;
		}
	}//end of for loop

	if(contactFound == false)
	{
		cout << "No contacts found" << endl;
	}

	return;
}//end of searchContacts

//function to create a file with the all the contacts
void saveContacts(vector<string>& first, vector<string>& last, vector<string>& numbers)
{
 	ofstream myfile;
  	myfile.open ("Contacts.txt");
 	myfile << "All of your contacts \n";

 	for(int i = 0; i < (first.size() - 1); ++i)	//runs through the vector printing out each element
	{
		myfile << (i + 1) << ": " << first.at(i) << " " << last.at(i) << " " << numbers.at(i) << endl;
	}

 	myfile.close();
	return;
}//end of save contacts

//function to sort the entries
void sortContacts(vector<string>& first, vector<string>& last, vector<string>& numbers)
{
	string tempFirst;
	string tempLast;
	string tempNum;

	for(int i = 0; i < (first.size() - 2); ++i)
	{
		if((first.at(i) > first.at(i + 1)))		//sorts by first name
		{
			tempFirst = first.at(i);			//temp variables assigned the first value
			tempLast = last.at(i);
			tempNum = numbers.at(i);

			first.at(i) = first.at(i + 1);		//first value assigned to second value
			last.at(i) = last.at(i + 1);
			numbers.at(i) = numbers.at(i + 1);

			first.at(i + 1) = tempFirst;		//second value assigned temp/first value
			last.at(i + 1) = tempLast;
			numbers.at(i + 1) = tempNum;

			i = -1;								//will resst the loop to 0 (-1+1=0)
		}//end of if statement
	}//end of for loop

	return;
}//end sortContacts

//beginnning of main function
int main()
{
	//three seperate vectors so they can be individually searched and if needed, manipulated
	vector<string> firstNames(1);
	vector<string> lastNames(1);
	vector<string> phoneNums(1);
	string indicator;
	string junk; 		//stores any excess improper inputs
	int removeContact;
	bool validInd = true;

	while(validInd == true)
	{
		cout << "If you would like to add an entry, enter \"Add\"" << endl <<
				"If you would like to delete an entry, enter \"Delete\"" << endl <<
				"If you would like to view all entries, enter \"Contacts\"" << endl <<
				"If you would like to search for an entry, enter \"Search\"" << endl <<
				"If you would like to sort (by first name) the entries, enter \"Sort\"" << endl <<
				"If you would like to save your contacts to document, enter \"Save\"" << endl <<
				"If you would like to end the program, enter \"Quit\"" << endl;
		cin >> indicator;
		getline(cin , junk); //prevent the loop from triggering multiple times if mulitple inputs are entered

		for(int i = 0; i < indicator.size(); ++i)	//converts indicator to all caps incase the user enters wrong
		{
			indicator.at(i) = toupper(indicator.at(i));
		}

		if(indicator == "ADD")//add an element
		{
			//call to function to add a contact
			addContact(firstNames , lastNames , phoneNums);
			cout << endl;
			continue;		//the continue statements prevent the code from executing twice
		}
		else if(indicator == "DELETE")
		{
			//call to function to remove a contact
			deleteContact(firstNames , lastNames , phoneNums);
			cout << endl;
			continue;
		}
		else if(indicator == "CONTACTS")
		{
			//call to function to display all contacts
			showContacts(firstNames , lastNames , phoneNums);
			cout << endl;
			continue;
		}
		else if(indicator == "SEARCH")
		{
			//call to function to display all contacts
			searchContacts(firstNames , lastNames , phoneNums);
			cout << endl;
			continue;
		}
		else if(indicator == "SORT") //to quit the loop
		{
			sortContacts(firstNames , lastNames , phoneNums);
			cout << endl;
			continue;
		}
		else if(indicator == "SAVE") //to quit the loop
		{
			saveContacts(firstNames , lastNames , phoneNums);
			cout << endl;
			continue;
		}
		else if(indicator == "QUIT") //to quit the loop
		{
			validInd = false;
			continue;
		}
		else
		{
			cout << "Invalid input, please enter a new indicator" << endl << endl;
			continue;
		}
	}//end of while loop
	return 0;
}//end of int main