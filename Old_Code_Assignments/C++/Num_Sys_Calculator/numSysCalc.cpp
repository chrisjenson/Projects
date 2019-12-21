/*==========================================================
 Author: Christopher Jenson
 Modified By: N/A
 Date:        5/9/2018

 Course: CSC-215
 File:  numSysCalc.cpp
 Rev #: 2.7
 Description: 1.0- The program currently asks the user for
 				   the type of number system is being used
 				   and there is a block of code for operators.
    			  1.1- Added a function for converting hex to dec.
    			  2.0- Created a function to intake the two inputs
    			  	   instead of two blocks of code and made the
    			  	   calculation portion its own function as well
    			  	   to clean up the main function.
    			  2.1- Added while loops to protect the code.
    			  2.2- Added binary to decimal function and changed
    			  	   ints to doubles to allow for non-whole number
    			  	   values.
    			  2.3- Added skeleton for converting the solution
    			  	   to the desired number system.
    			  2.4- Can convert the solution to bin or hex now.
    			  2.5- Now tests for valid decimal, binary, and
    			  	   hexadecimal inputs. No longer requires
    			  	   capitalized hex inputs.
    			  2.6- Cleaned up int main by adding a function
    			  	   to be called that starts the program.
    			  2.7- Added more flexibility for user inputs.
 ============================================================*/

#include <iostream>
#include <cstring>		//included for string variable type and strlen function
#include <cctype>		//included for isdigit and isalpha functions

using namespace std;

//Function to convert binary to decimal
int binaryToDecimal(int binInput)
{
	//declaring variables
   int decVal = 0;
	int temp = binInput;
	int lastDigit;
   int base = 1;	//starting base value at 1, 2^0

   while(temp)
   {
      lastDigit = (temp % 10);
      temp = (temp / 10);

      decVal += (lastDigit * base);

      base *= 2;

   }//end of while loop
   return decVal;
}//end of binaryToDecimal function

//Function to perform the desired math function
double doesMath(double valOne, double valTwo)
{
	double answer = 0;
	string mathFunction;
	bool getNum = false;	//used to test whether the user entered a vaild operator

	//block of code for indentifing the operator and then performing that operator
    while(getNum == false)		//created a loop incase the user enters a unsupported operator
    {
   		//Asks for and assigns the operator
  		cout << "Please enter the mathematical operator you would like to use (ex: +): " << endl;
  	  	getline(cin , mathFunction);

   		//if/else functions
   		if(mathFunction == "+")
   		{
			answer = (valOne + valTwo);
			getNum = true;
			return answer;
		}
		else if(mathFunction == "-")
		{
			answer = (valOne - valTwo);
			getNum = true;
			return answer;
		}
		else if((mathFunction == "x") || (mathFunction == "*")) //incase the user doesnt know to use *
		{
			answer = (valOne * valTwo);
			getNum = true;
			return answer;
		}
		else if(mathFunction == "/")
		{
			cout << "Divison may result in loss of accuracy if the numbers do not divide evenly" << endl;
			answer = (valOne / valTwo);
			getNum = true;
			return answer;
		}
		else
		{
			cout << "Invalid Input, please enter again" << endl << endl;
		}
	}//end of while loop
}//end of doesMath function

//Function to convert hexadecimal to decimal
int hexadecimalToDecimal(char hexVal[])
{
	//Declaring Variables
  	int length = strlen(hexVal); //gets length of hexVal
   int decVal = 0;
   int base = 1;  	//starting at base value of 1

   //taking the last char and using the ASCII value to compute
   for (int i = (length - 1); i >= 0; i--)
   {
      //if char between 0-9, subtract 48 from ASCII value
      if ((hexVal[i] >= '0') && (hexVal[i] <= '9'))
      {
         decVal += ((hexVal[i] - 48) * base);

          //increment base by the power
          base *= 16;
      }//end of if statement

      //if char between A-F, convert to 10-15 by subtracting 55 from ASCII value
      else if ((hexVal[i] >= 'A') && (hexVal[i] <= 'F'))
      {
          decVal += ((hexVal[i] - 55) * base);

          //increment base by the power
          base *= 16;
      }
  }//end of for loop
  return decVal;
}//end of hexadecimalToDecimal

//Function to determine the input type and then convert to decimal
double determineInputType(string numSystem)
{
	//declaring variables
	int binNum = 0;
	char hexNum[] = "1A"; //just some starting value
	bool validInput = true;
	double inputValue = 0;
	string input;	//used to perform character operations

	if(numSystem == "DEC")	//for decimal numbers
	{
		while(validInput == true)	//will fire untill a valid input is entered
		{
			cout << "Please enter your base 10 (decimal) number:" << endl;
			getline(cin , input);

			bool didPass = true;		//needs to be in the loop so it resets each time (learned the hard way)

			for(int i = 0; i < input.size(); ++i)	//runs through each element of the string
			{
				if(isdigit(input.at(i)) == false)	//if an element is not a number, go back to top
				{
					cout << "Invalid Input, enter again" << endl << endl;
					didPass = false;		//will prevent the following if statement from firing
					break;
				}
			}//end of for loop

			if(didPass == true)		//only triggers if the for loop only finds numbers
			{
				inputValue = stoi(input , nullptr, 10);		//converts the number in a string to a int value
				validInput = false;		//kills the while loop
				cout << endl;
			}//end of if statement
		}//end of while loop
	}//end of Dec if statement

	else if(numSystem == "BIN")	//for binary numbers
	{
		while(validInput == true)	 //will fire untill a valid input is entered
		{
			cout << "Please enter your base 2 (binary) number (up to ten digits):" << endl;
			getline(cin , input);

			bool didPass = true;

			for(int j = 0; j < input.size(); ++j)	//runs through each element of the string
			{
				if(!((input.at(j) == '1') || (input.at(j) == '0')))		//tests each element if 1 or 0 since only values for binary
				{
					cout << "Invalid Input, enter again" << endl << endl;
					didPass = false;		//will prevent the following if statement from firing
					break;
				}
			}//end of for loop

			if(didPass == true)		//only triggers if the for loop only finds 1's and 0's
			{
				binNum = stoi(input , nullptr, 10);		//converts the number in a string to a int value
				inputValue = binaryToDecimal(binNum);	 //returns converted value
				validInput = false;		//kills the while loop
				cout << endl;
			}//end of if statement
		}//end of while loop
	}//end of Bin if statement

	else if(numSystem == "HEX")	//for hexadecimal numbers
	{
		while(validInput == true)	 //will fire untill a valid input is entered
		{
			cout << "Please enter your base 16 (hexadecimal) number (letters do not have to be capitalized):" << endl;
    		cin >> hexNum;
    		cin.clear();	//in case of a failed state
    		cin.ignore();

    		bool didPass = true;

    		for(int k = 0; k < strlen(hexNum); k++) //goes through each element of hexNum
    		{
				if(isalpha(hexNum[k]))	//finds all characters
				{
					hexNum[k] = toupper(hexNum[k]);			//makes them uppercase

					if((hexNum[k] < 65) || (hexNum[k] > 70))	//test if their ASCII value is between 65 and 70
					{
						cout << "Invalid Input, enter again" << endl << endl;
						didPass = false;		//will prevent the following if statement from firing
						break;
					}
				}//end of if statement
			}//end of for loop

			if(didPass == true)		//only triggers if the for loop only finds 1's and 0's
			{
				inputValue = hexadecimalToDecimal(hexNum); //returns converted value
				validInput = false;		//kills the while loop
				cout << endl;
			}
		}//end of while loop
	}//end of Hex if statement
	return inputValue;
}//end of determineInputSystem

//function to convert the solution to the desired number system
void convertSolution(double decVal)
{
	//declaring variables
	int remainder = 0;
	int bin[64];	//will store the binary in reverse order
	int i = 0;
	int wholeNum = decVal; //bin and hex conversion needs whole number
	char hexNum[100]; //will store the hex value in reverse order
	string solSys; //solution number system

	cout << endl << "Please specify what type of number system you would like the solution in by entering \"Bin\", \"Hex\", or \"Dec\"" << endl;
	cin >> solSys;

	for(int i = 0; i < solSys.size(); ++i)
	{
		solSys.at(i) = toupper(solSys.at(i));
	}

	if((solSys == "DEC") || (decVal == 0)) //no conversions needed
	{
		cout << "The solution in base 10 is: " << decVal << endl;
	}

	else if(solSys == "BIN") //converts to binary
	{
		cout << "The solution in base 2 is: ";
		while(wholeNum != 0)
		{
		  	remainder = (wholeNum % 2);
		  	bin[i++] = remainder;
		  	wholeNum /= 2;
		}

		for(int j = (i - 1); j >= 0; j--) //prints arr in reverse order
		{
			cout << bin[j];
		}
		cout << endl;
	}//end of if bin

	else if(solSys == "HEX")
	{
		cout << "The solution in base 16 is: ";

		//code to convert to hexadecimal
		while(wholeNum != 0)
		{
		   	//finding the remainder
		    remainder = (wholeNum % 16);

		    if(remainder < 10)	//1-9
		    {
			    hexNum[i] = (remainder + 48);
		        i++;
		    }
		    else	//10-15 or A-F
		    {
		    	hexNum[i] = (remainder + 55);
	        	i++;
		    }
			wholeNum /= 16;
		}//end of while loop

		// loop prints array in reverse order
		for(int j = (i - 1); j >= 0; j--)
		{
       		cout << hexNum[j];
		}
		cout << endl;
	}
	return;
}//end of convertSolution

//function to get the desired number system
int getNumberSystem()
{
	string givenSys;	//Input type variables
	bool isNumSys = false;
	double value;

	while(isNumSys == false)
	{
		cout << "Please specify what type of number system your input is using by entering \"Bin\", \"Hex\", or \"Dec\"" << endl
			 << "(non-whole numbers are not supported)" << endl;
		getline(cin , givenSys);

		for(int i = 0; i < givenSys.size(); ++i)	//converts givenSys to all caps incase the user enters wrong
		{
			givenSys.at(i) = toupper(givenSys.at(i));
		}

		if((givenSys == "BIN") || (givenSys == "HEX") || (givenSys == "DEC"))
		{
			value = determineInputType(givenSys);	//calls a function to determine, if any, what conversions need to be executed
			isNumSys = true;		//stops the while loop from executing again
		}
		else
		{
			cout << "Invalid input, please enter again" << endl << endl;
		}
	}//end of while loop

	return value;
}//end of getNumberSystem

//start of main function
int main()
{
	//Declaring Variables
	double solution;
	double inputOne;
	double inputTwo;

	//calls for the input of a desired number system
	inputOne = getNumberSystem();
	inputTwo = getNumberSystem();

	//calls for the computation of the solution
	solution = doesMath(inputOne, inputTwo);
	//converts the solution to the desired value and then outputs it from the other function
	convertSolution(solution);

	return 0;
}//end of int main