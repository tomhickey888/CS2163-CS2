//Hickey, Thomas    Matzen    Spring 2014    Program 7B
//Overview: Gets a file name from the user and reads from the file the into an array of structs
//			The program then outputs the array to the screen after determining the classification
//          of the student and their eligibility for the honor society. Compiled with multiple files.
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "common.h"

using namespace std;

int displayData(student studentData[], int H);

int main()
{
  // Array to store student structs
  student studentData[MAX_STUDENTS];

  // Header variable, placeholder for reading integers from text file and an accumulator
  int H, tempInt, acc = 0;

  // Placeholder for reading floats from text file
  float tempFloat;

  // Variable to hold file name
  string fname;

  ifstream inFile;

  // Gets filename from user
  cout << "Please enter the name of your input file: ";
  	  cin >> fname;
  cout << endl;

  inFile.open(fname.c_str());

  // Defensive programming for bad user input for filename
  if(!inFile)
    {
  	  cout << endl << "Cannot find and open input file " << fname << "." << endl << endl;
      exit(0);
    }

  // Reads in Header number
  inFile >> H;

  // Defensive programming for too many numbers in the file for the arrays
  while(H > MAX_STUDENTS || H <= 0)
  {
	  cout << endl << "Data Error. Cannot process a file with " << H << " numbers in it. " << endl << endl;
      exit(0);
  }

  // Reads file into structs/array
  for(int i=0; i < H; i++)
  {
 	  inFile >> tempInt;
	  studentData[i].ID = tempInt;
	  inFile >> tempInt;
	  studentData[i].hours = tempInt;
	  inFile >> tempFloat;
	  studentData[i].GPA = tempFloat;
  }

  // Displays completed array
  acc = displayData(studentData, H);

  cout << endl << "Total number of students eligible for the Honor Society is " << acc << "." << endl << endl;

  inFile.close();
}