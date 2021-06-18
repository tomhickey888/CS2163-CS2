#include <iostream>
#include <iomanip>
#include <cstdlib>
#include  <ctime>
#include "common.h"

using namespace std;

// Initializes the slot wheel symbols for each slot and seeds the random number generator
void initializeSlot(wheel slotWheels[])
{
	for(int i=0; i < NUM_WHEELS; i++)
	    strcpy(slotWheels[i].symbols, wheelSymbols);
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
            // Generates a random number as the spin result
		    slotWheels[i].spinPos = rand();

	        // Scales the random number down to 0-29
		    slotWheels[i].spinPos = slotWheels[i].spinPos % SCALE;

	        // Sets the spin symbol for the active wheel
	        slotWheels[i].spinSymbol = slotWheels[i].symbols[slotWheels[i].spinPos];
		}

        cout << slotWheels[0].spinSymbol << slotWheels[1].spinSymbol << slotWheels[2].spinSymbol << endl;

        if(slotWheels[0].spinSymbol == slotWheels[1].spinSymbol && slotWheels[1].spinSymbol == slotWheels[2].spinSymbol)
            cout << "Winner! Matched 3 of " << slotWheels[0].spinSymbol << endl;
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
		    // Generates a random number as the spin result
	        slotWheels[i].spinPos = rand();

			// Scales the random number down to 0-29
			slotWheels[i].spinPos = slotWheels[i].spinPos % SCALE;

			// Sets the spin symbol for the active wheel
			slotWheels[i].spinSymbol = slotWheels[i].symbols[slotWheels[i].spinPos];
		}

        if(slotWheels[0].spinSymbol == slotWheels[1].spinSymbol && slotWheels[1].spinSymbol == slotWheels[2].spinSymbol)
        {
			if(slotWheels[0].spinSymbol == 'X')
			    win1++;

			else if(slotWheels[0].spinSymbol == '-')
			    win2++;

			else if(slotWheels[0].spinSymbol == '=')
			    win3++;

			else if(slotWheels[0].spinSymbol == '*')
			    win4++;

			else if(slotWheels[0].spinSymbol == '@')
			    win5++;

			else
			    win6++;
		}
	}

	cout << "X won " << win1 << " times" << endl << "- won " << win2 << " times" << endl << "= won " <<
		win3 << " times" << endl << "* won " << win4 << " times" << endl << "@ won " << win5 << " times" <<
		endl << "7 won " << win6 << " times" << endl;
}