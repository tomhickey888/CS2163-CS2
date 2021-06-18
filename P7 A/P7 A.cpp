//Hickey, Thomas    Matzen    Spring 2014    Program 7A
//Overview: Gets a file name from the user and reads from the file the into an array of structs
//			The program then outputs the array to the screen after determining the classification
//          of the student and their eligibility for the honor society.
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

//Globally declared struct for students
struct student
{
  int ID;
  int hours;
  float GPA;
};

int main()
{
  // Named constant for array size
  const int MAX_STUDENTS = 10;

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
  for(int i=0; i < H; i++)
  {
    cout << "Student #" << studentData[i].ID << " is a ";

    // Determines classification and eligibility of each student
    if(studentData[i].hours < 30)
        cout << "freshman with a GPA of " << showpoint << setprecision(3) << studentData[i].GPA << "." << setw(21) << "Not eligible.";

    else if(studentData[i].hours < 60)
    {
        cout << "sophomore with a GPA of " << showpoint << setprecision(3) << studentData[i].GPA << ".";

        if(studentData[i].GPA >= 3.75)
        {
            cout << setw(20) << "Eligible.";
            acc++;
		}

		else
		    cout << setw(20) << "Not eligible.";
	}

    else if(studentData[i].hours < 90)
    {
        cout << "junior with a GPA of " << showpoint << setprecision(3) << studentData[i].GPA << ".";

        if(studentData[i].GPA >= 3.5)
		{
			cout << setw(23) << "Eligible.";
		    acc++;
		}

		else
		    cout << setw(23) << "Not eligible.";
	}

    else
    {
        cout << "senior with a GPA of " << showpoint << setprecision(3) << studentData[i].GPA << ".";

        if(studentData[i].GPA >= 3.25)
	    {
			cout << setw(23) << "Eligible.";
		    acc++;
		}

		else
		    cout << setw(23) << "Not eligible.";
	}

    cout << endl;
  }

  cout << endl << "Total number of students eligible for the Honor Society is " << acc << "." << endl << endl;

  inFile.close();
}