//Hickey, Thomas    Matzen    Spring 2014    Program 6A
//Overview: Gets a file name from the user and reads from the file the into three arrays, processes
//			the numbers in the arrays to find the largest and smallest numbers in each row, and
//          outputs the result using dynamic memory allocation for the array sizes.
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

// 7 lines commented out     4 lines added

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int largest(int, int, int);
int smallest(int, int, int);

int main()
{
  // Named constant for array sizes
  // const int MAX=15;

  // Arrays to store text file integers
  // int a1[MAX], a2[MAX], a3[MAX];

  // Pointer variables for dynamic memory allocation
  int *a1, *a2, *a3;

  // Header variable and placeholder for reading integers from text file
  int H, num;

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

  // Creates the three arrays with dynamic memory allocation for the sizes to be equal to the header
  a1 = new int[H];
  a2 = new int[H];
  a3 = new int[H];

  // Defensive programming for too many numbers in the file for the arrays
  // while(H > MAX || H <= 0)
  // {
  // cout << endl << "Data Error. Cannot process a file with " << H << " numbers in it. " << endl << endl;
  // exit(0);
  // }

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

  // Frees dynamic memory allocated for arrays and closes file opened during program execution
  delete [] a1;
  delete [] a2;
  delete [] a3;

  inFile.close();
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