//Hickey, Thomas    Matzen    Spring 2014    Program 10
//Overview: A program to simulate a slot machine using an array of classes for the wheels
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

#include <iostream>
#include <cstdlib>
#include "common.h"

using namespace std;

// Function prototypes
void initializeSlot(wheel slotWheels[]);
void displaySlotsA(wheel slotWheels[], int numSpins);
void displaySlotsT(wheel slotWheels[], int numSpins);

int main()
{
  // Array to store slot wheel classes
  wheel slotWheels[NUM_WHEELS];

  // Variable for the number of spins
  int numSpins;

  // Variables for the user's choice of display and exit
  char displayChoice, exitChoice;

  // Variable for loop control
  bool exit=0;

  do
  {
	  // Gets the number of spins from the user
      cout << "How many times do you want to spin the wheel: ";
     	  cin >> numSpins;
      cout << "Do you want to see Totals only or All spins and winners (T/A): ";
          cin >> displayChoice;

      // Function call to display totals only
      if(displayChoice == 'T' || displayChoice == 't')
		  displaySlotsT(slotWheels, numSpins);

      // Function call to display all spins
      else if(displayChoice == 'A' || displayChoice == 'a')
		  displaySlotsA(slotWheels, numSpins);

	  // Defensive programming for bad user input
	  else
	      cout << "Please enter either T for totals only or A for all spins and winners" << endl;

	  // Allows user the option to quit or spin again
	  cout << "Would you like to spin again (Y/N): ";
	    cin >> exitChoice;

	  // Continues the loop
	  if(exitChoice == 'Y' || exitChoice == 'y')
	      exit = 0;

	  // Exits the loop
	  else if(exitChoice == 'N' || exitChoice == 'n')
	      exit = 1;

	  // Defensive programming for bad user input
	  else
	      cout << "Please enter either Y to spin again or N to halt the program." << endl;

  } while(exit == 0);

  cout << "Goodbye!" << endl << endl;
}