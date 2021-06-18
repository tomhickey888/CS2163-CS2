//Hickey, Thomas    Matzen    Spring 2014    Program 4A
//Overview:  An interactive program to read in a ASCII text from a file and output the text to another
//           file with any spaces replaced by 'X'.  It also counts the number of characters and the number
//           of spaces that have been replaced.
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

  // Variables for the input and output filenames entered by the user
  string inFname, outFname;

  // Variables for the counters for characters and for replacements made
  int cnt = 0;
  int cntRepl = 0;

  // Variable for the ASCII character being read from and written to files
  char ch;

  // User input for filename of the input file
  cout << "Please enter your input file name:  ";
  	  cin >> inFname;

  ofstream outFile;
  ifstream inFile;

  inFile.open(inFname.c_str());

  // Defensive programming for bad input filename
  if(!inFile)
  {
    cout << endl << "Error: Cannot find and open input file " << inFname << "." << endl << endl;
    exit(0);
  }

  // User input for filename of the output file
  cout << "Please enter your output file name:  ";
  	  cin >> outFname;

  outFile.open(outFname.c_str());

  // Defensive programming for inability to open output file
  if(!outFile)
  {
    cout << endl << "Error: Cannot open new file " << outFname << "." << endl << endl;
    exit(0);
  }

  // Performs the first character get function to allow the loop to terminate correctly at end of file
  inFile.get(ch);

  // Loop to get information from the input file and write it to the output file
  while (!inFile.eof())
  {
	  // If statement to catch spaces and replace them
	  if(ch == ' ')
	  {
		  outFile.put('X');
		  cnt++;
		  cntRepl++;
	  }

	  // Else statement to write character directly to output file
	  else
	  {
		  outFile.put(ch);
          cnt++;
	  }

	  // Gets the next character so that when end of file is reached the loop can terminate on time
	  inFile.get(ch);

    }

  // Display the number of characters in the file
  cout << "The total number of characters in the file is " << cnt << endl;

  // Display the number of spaces found and replaced
  cout << "The number of spaces found and replaced is " << cntRepl << endl;

  cout << endl;

  // Closes files opened during program execution
  outFile.close();
  inFile.close();
}