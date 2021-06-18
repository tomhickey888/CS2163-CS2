//Hickey, Thomas    Matzen    Spring 2014    Program 1
//Overview: Gets a file name from the user and reads from the file the into three arrays, processes
//			the numbers in the arrays to find the largest and smallest numbers in each row, and
//          outputs the result.
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int largest(int, int, int);
int smallest(int, int, int);

int main()
{
  const int MAX=15; // Named constant for array sizes
  int a1[MAX], a2[MAX], a3[MAX]; // Arrays to store text file integers
  int H, num; // Header variable and placeholder for reading integers from text file
  string fname; // Variable to hold file name

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
  while(H > MAX || H <= 0)
  {
	  cout << endl << "Data Error. Cannot process a file with " << H << " numbers in it. " << endl << endl;
	  exit(0);
  }
// Reads file integers into arrays
  for(int i=0; i < H; i++)
  {
 	  inFile >> num;
	  a1[i] = num;
	  inFile >> num;
	  a2[i] = num;
	  inFile >> num;
	  a3[i] = num;
  }
// Displays completed arrays
  cout << setw(10) << "Array1" << setw(10) << "Array2" << setw(10) << "Array3" << endl;

  for(int i=0; i < H; i++)
  {
    cout << setw(10) << a1[i] << setw(10) << a2[i] << setw(10) << a3[i] << endl;
  }

// Uses functions to calculate the largest and smallest integers in each row and displays them
  cout << endl << setw(10) << "Smallest" << setw(10) << "Largest" << endl;

  for(int i=0; i < H; i++)
  {
 	  cout << setw(10) << smallest(a1[i], a2[i], a3[i]) << setw(10) << largest(a1[i], a2[i], a3[i]) << endl;
  }

  cout << endl << endl;
}
// Function used to calculate the largest integer of each row
int largest(int n1, int n2, int n3)
  {
	int largest;

	if(n1 >= n2 && n1 >= n3)
	    largest = n1;

	else if(n2 >= n1 && n2 >= n3)
	    largest = n2;

	else if(n3 >= n1 && n3 >= n2)
	    largest = n3;

	return largest;
  }
// Function used to calculate the smallest integer of each row
int smallest(int n1, int n2, int n3)
  {
	  int smallest;

	  if(n1 <= n2 && n1 <= n3)
	  	    smallest = n1;

	  	else if(n2 <= n1 && n2 <= n3)
	  	    smallest = n2;

	  	else if(n3 <= n1 && n3 <= n2)
	  	    smallest = n3;

	return smallest;
  }