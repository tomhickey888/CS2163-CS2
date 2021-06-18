//Hickey, Thomas    Matzen    Spring 2014    Program 4B
//Overview:  A program that will open and read any text file, read the in the input file one character
//           at a time, count the number of each ASCII character that occurs in the file, and output the
//           character count to the screen.
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
  //Constant value for ASCII characters
  const int ASCII = 127;

  //Array of counters for ASCII characters initialized at 0
  int cntr[ASCII] = {};

  // Variable for the filename entered by the user
  string fName;

  // Variable for the counter for characters and for character conversion
  int cnt = 0;

  // Variable for the ASCII character being read from and written to files
  char ch;

  // User input for filename of the input file
  cout << "Please the name of the input file:  ";
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

  // Performs the first character get function to allow the loop to terminate correctly at end of file
  inFile.get(ch);

  // Loop to get information from the input file and increment the counter for that character
  while (!inFile.eof())
  {
	  cntr[ch]++;
	  cnt++;

	  // Gets the next character so that when end of file is reached the loop can terminate on time
	  inFile.get(ch);

  }

  // Display the formatted ASCII counter results
  cout << setw(3) << "ASCII" << setw(8) << "Count" << endl;

  for (int i=0; i < ASCII; i++)
	  if(cntr[i] > 0)
		  cout << setw(3) << i << setw(8) << cntr[i] << endl;

  // Display the number of characters in the file
  cout << endl << "The total number of characters in the file is " << cnt << endl;

  cout << endl;

  // Closes files opened during program execution
  inFile.close();
}