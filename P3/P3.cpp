//Hickey, Thomas    Matzen    Spring 2014    Program 3
//Overview:  An interactive program to read in a list of numbers from a file, store them in an array,
//           sort the array into ascending order, and allow the user to search the array for a number
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

// Global named constants for array size and numbers printed per line
const int MAX_NUMS=100;
const int NUMS_PER_LINE=10;

// Function prototypes for displaying the array, checking to see if it;s sorted, sorting it, and searching it
void printList (int list[], int N, int NUMS_PER_LINE);
bool checkList (int list[], int N);
void sortList (int list[], int N);
int searchList (int list[], int N, int key);


int main()
{

  // Array for the list of numbers
  int list[MAX_NUMS];

  // Variable for the filename entered by the user
  string fname;

  // Variables for the header number and the numbers as they are read into the array
  int N, listNum;

  // Variable for the choice entered by the user during the search loop
  char choice;

  // Variables for the number sought by the user and the position it may be in
  int key, pos;

  // Variable used as a flag for when the user chooses to quit
  bool quit = false;

  // User input for filename of number list
  cout << "Please enter the input file name:  ";
  	  cin >> fname;

  ifstream inFile;
  inFile.open(fname.c_str());

  // Defensive programming for bad filename
  if(!inFile)
  {
    cout << endl << "Cannot find and open input file " << fname << "." << endl << endl;
    exit(0);
  }

  // Reads in the header number from the file
  inFile >> N;

  // Defensive programming for a header number too large/small
  while(N > MAX_NUMS || N <= 0)
  {
  	cout << endl << "Data Error. Cannot process a file with " << N << " numbers in it." << endl << endl;
  	exit(0);
  }

  // Reads the file and inputs the data into the array
  for(int i = 0; i < N; i++)
  {
    inFile >> listNum;
  	list[i] = listNum;
  }

  // Displays the array elements to the screen, 10 elements per line
  cout << endl << "The elements in the list are:" << endl;

  printList(list, N, NUMS_PER_LINE);

  // Checks the list to see if it is in ascending order, sorts if necessary
  if(checkList(list, N))
  	  cout << endl << "The list is in ascending order." << endl << endl;

  else
  {
	  cout << endl << "The list is not in ascending order." << endl << endl;
	  sortList(list, N);
	  cout << "The list is now in ascending order:" << endl;
	  printList(list, N, NUMS_PER_LINE);
	  cout << endl;
  }

  // Repeatedly asks the user to enter a number until they choose to quit
  do
  {
	  cout << "Do you want to look for a number in the list (Y/N):  ";
  	      cin >> choice;

      if(choice == 'Y' || choice == 'y')
      {
	      cout << "Enter your number:  ";
	      	cin >> key;

	      pos = searchList(list, N, key);

	      if(pos >= 0)
	          cout << key << " is in position " << pos+1 << " in the list." << endl << endl;
	      else
	          cout << key << " is not in the list." << endl << endl;
      }

      else if(choice == 'N' || choice == 'n')
      {
		  quit = true;
	  }

      else
          cout << endl << "Please choose either Y to search or N to quit." << endl << endl;

	} while(!quit);

	cout << endl << "Goodbye!" << endl << endl;
}

// Function used to display the list of numbers in the array
void printList (int list[], int N, int NUMS_PER_LINE)
{
	int acc=0;

	for (int i = 0; i <= N/10; i++)
	{
		for(int j = 0; j < NUMS_PER_LINE && acc < N; j++)
		{
		    cout << list[acc] << " ";
		    acc++;
		}

		cout << endl;
	}
}

// Function used to check the array to see if it is in ascending order
bool checkList (int list[], int N)
{
	bool flag = true;
	for(int i = 0; i < N-1 && flag == true; i++)
	{
		if(list[i] <= list[i+1])
			flag = true;
		else
			flag = false;
	}

	if(flag == true)
	    return true;
	else
	    return false;
}

// Function used to bubble sort the array into ascending order
void sortList (int list[], int N)
{
	int temp, loop, pos;

	int last = N-1;

	for(loop = 1; loop < N-1; loop++)
	{
		for(pos = 0; pos < last; pos++)
		{
			if(list[pos] > list[pos+1])
			{
				temp = list[pos];
				list[pos] = list[pos+1];
				list[pos+1] = temp;
			}
		}

		last--;
	}
}

// Function used to binary search the array
int searchList (int list[], int N, int key)
{
	int first = 0, last = N-1, middle, pos = -1;
	bool found = false;

	while(!found && first <= last)
	{
		middle = (first + last) / 2;

		if(list[middle] == key)
		{
			found = true;
			pos = middle;
		}

		else if(list[middle] > key)
			last = middle - 1;

		else
			first = middle + 1;

	}

	return pos;
}