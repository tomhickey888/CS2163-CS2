//Hickey, Thomas    Matzen    Spring 2014    Program 5
//Overview:  A program that will open and read any text file, read the in the a list of names from the
//           file, store the names as an array of character strings, output the array to the screen,
//           and allow the user to search the array for a name that they enter.
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

// Global defined constants for the array dimensions
const int MAX_NAMES = 10;
const int MAX_NAME_LENGTH = 50;

// Function prototype for function to print names to the screen
void printNames(char [][MAX_NAME_LENGTH+1], int);

// Function prototype for linear search
int searchNames(char [][MAX_NAME_LENGTH+1], int, char[]);

int main()
{
  // 2D array of characters for the C strings
  char names[MAX_NAMES][MAX_NAME_LENGTH+1];

  // Character array for the name searched for by the user
  char name[MAX_NAME_LENGTH+1];

  // Variables for the filename entered by the user and the name searched for by the user
  string fName;

  // Variable for the header number read from the file
  int H;

  // Variable for the user response for file name searching loop
  char resp;

  // User input for filename of the input file
  cout << "Please the name of your input file:  ";
  	  cin >> fName;
  cout << endl;

  ifstream inFile;

  inFile.open(fName.c_str());

  // Defensive programming for bad input filename
  if(!inFile)
  {
    cout << endl << "Error: Cannot find and open input file " << fName << "." << endl << endl;
    exit(0);
  }

  // Reads in the first number in the file as the header number
  inFile >> H;

  // Defensive programming for too many/not enough names in the file
  while(H > MAX_NAMES || H <= 0)
  {
	  cout << endl << "Data Error. Cannot process a file with " << H << " numbers in it." << endl << endl;
	  exit(0);
  }

  // Reads file character strings into the array
  for(int i=0; i < H; i++)
  {
 	  inFile >> names[i];
  }

  // Displays the names after reading them into the array
  printNames(names, H);

  cout << endl;

  // Loop to repeatedly ask the user if they wish to search for a name
  do
  {
	  cout << "Do you wish to search for a name: ";
	  	cin >> resp;

	  // Gets the name to search for from the user if they chose to search
	  if(resp == 'Y' || resp == 'y')
	  {
		  cout << "Enter name: ";
		  	cin >> name;

		  //Linear search for name entered by the user
		  int index = searchNames(names, H, name);

		  // If found displays the position in 1-based indexing
		  if(index >= 0)
		     cout << name <<" found in position " << index+1 << endl << endl;

		  // If not found displays a message
		  else
		    cout << name << " not found" << endl << endl;

	  }
  } while(resp == 'Y' || resp == 'y');

  cout << "Goodbye!" << endl << endl;

  // Closes files opened during program execution
  inFile.close();
}

// Function to display names to screen
void printNames(char names[][MAX_NAME_LENGTH+1], int nameCount)
{
	cout << "Output Names:" << endl;

	for(int row = 0; row < nameCount; row++)
		{
			cout << names[row] << endl;
    	}
}

// Function to linear search the names
int searchNames(char names[][MAX_NAME_LENGTH+1], int header, char name[])
{
   int index = 0;
   int position = -1;

   bool found = false;

   // Loop for searching the array
   while (index < header && !found)
   {
      // If the value is found
      if (strcmp(names[index], name) == 0)
       {
		   // Set the flag
           found = true;

           // Record the position
           position = index;
       }

       index++;
   }

   // Return the position (or -1 if not found)
   return position;
}
