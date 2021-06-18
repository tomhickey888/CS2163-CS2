#include <iostream>
#include <iomanip>
#include <cstdlib>
#include  <ctime>
#include "common.h"

using namespace std;

// Initializes the slot wheel symbols for the wheel on construction
wheel::wheel(void)
{
	strcpy(symbols, wheelSymbols);
}

//Sets the spinPos and spinSymbol
void wheel::setSpinPos(int num)
{
	spinPos = num % SCALE;
	spinSymbol = symbols[spinPos];
}

// Gets the spinPos
int wheel::getSpinPos(void)
{
	return spinPos;
}

// Gets the spinSymbol
char wheel::getSpinSymbol(void)
{
	return spinSymbol;
}

//Displays the slot's current results with all spins shown
void displaySlotsA(wheel slotWheels[], int numSpins)
{
	// Generates the seed to be used for the random number generator
	time_t seed;

	// Fills the seed with the calender time from the system
    time(&seed);

    // Seeds the generator used by the random number function
    srand(seed);

    for(int i=0; i < numSpins; i++)
    {
		for(int i=0; i < NUM_WHEELS; i++)
		{
            // Generates a random number as the spin result and sets the spin symbol
		    slotWheels[i].setSpinPos(rand());
		}

        cout << slotWheels[0].getSpinSymbol() << slotWheels[1].getSpinSymbol() << slotWheels[2].getSpinSymbol() << endl;

        if(slotWheels[0].getSpinSymbol() == slotWheels[1].getSpinSymbol() && slotWheels[1].getSpinSymbol() == slotWheels[2].getSpinSymbol())
            cout << "Winner! Matched 3 of " << slotWheels[0].getSpinSymbol() << endl;
    }
}

//Displays the slot's current results with only total winning spins shown
void displaySlotsT(wheel slotWheels[], int numSpins)
{
	int win1=0, win2=0, win3=0, win4=0, win5=0, win6=0;

	// Generates the seed to be used for the random number generator
	time_t seed;

	// Fills the seed with the calender time from the system
	time(&seed);

	// Seeds the generator used by the random number function
    srand(seed);

    for(int i=0; i < numSpins; i++)
    {
        for(int i=0; i < NUM_WHEELS; i++)
		{
			// Generates a random number as the spin result and sets the spin symbol
		    slotWheels[i].setSpinPos(rand());
		}

        if(slotWheels[0].getSpinSymbol() == slotWheels[1].getSpinSymbol() && slotWheels[1].getSpinSymbol() == slotWheels[2].getSpinSymbol())
        {
			if(slotWheels[0].getSpinSymbol() == 'X')
			    win1++;

			else if(slotWheels[0].getSpinSymbol() == '-')
			    win2++;

			else if(slotWheels[0].getSpinSymbol() == '=')
			    win3++;

			else if(slotWheels[0].getSpinSymbol() == '*')
			    win4++;

			else if(slotWheels[0].getSpinSymbol() == '@')
			    win5++;

			else
			    win6++;
		}
	}

	cout << "X won " << win1 << " times" << endl << "- won " << win2 << " times" << endl << "= won " <<
		win3 << " times" << endl << "* won " << win4 << " times" << endl << "@ won " << win5 << " times" <<
		endl << "7 won " << win6 << " times" << endl;
}