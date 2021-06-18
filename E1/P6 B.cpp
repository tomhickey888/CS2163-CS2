//Hickey, Thomas    Matzen    Spring 2014    Program 6B
//Overview: Gets a file name from the user, reads employee info from the file the into three arrays, outputs
//			the data from the arrays to the screen, and then outputs the total number of employees found.
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
  // Named constant for array sizes
  const int MAX=10;

  // Arrays to store text file integers
  int id[MAX], hours[MAX];

  // Array to store text file doubles
  double rate[MAX];

  // Placeholder for reading integers and doubles from text file
  int num;
  double pay;

  // Accumulator for total number of employees
  int acc=0;

  // Variable to hold file name
  string fname;

  ifstream inFile;

  // Gets filename from user
  cout << "Enter the name of your input file: ";
  	  cin >> fname;
  cout << endl;

  inFile.open(fname.c_str());

  // Defensive programming for bad user input for filename
  if(!inFile)
    {
  	    cout << endl << "Cannot find and open input file " << fname << "." << endl << endl;
        exit(0);
    }

  // Reads file data into arrays
  while(!inFile.eof())
  {
 	  inFile >> num;
	  id[acc] = num;
	  inFile >> num;
	  hours[acc] = num;
	  inFile >> pay;
	  rate[acc] = pay;

	  if(inFile.fail())
		  break;

  	  acc++;
  }

  // Defensive programming for too many numbers in the file for the arrays
  while(acc > MAX || acc <= 0)
  {
      cout << endl << "Data Error. Cannot process a file with " << acc << " employees in it." << endl << endl;
      exit(0);
  }

  // Displays completed arrays
  cout << setw(10) << "ID" << setw(10) << "Hours" << setw(10) << "Rate" << endl;

  for(int i=0; i < acc; i++)
  {
      cout << setw(10) << id[i] << setw(10) << hours[i] << setw(10) << fixed << showpoint << setprecision(2) << rate[i] << endl;
  }

  // Displays the number of employees detected in the file
  cout << endl << "There are " << acc << " employees in file " << fname << endl << endl;

  // Closes file opened during program execution
  inFile.close();

}