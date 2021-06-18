//Hickey, Thomas    Matzen    Spring 2014    Program 8
//Overview: Repeatedly ask the user if they want to roll a pair of dice; then get two pseudorandom
//			numbers between 1 and 6 using the C based random number generator.
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

#include  <iostream>
#include  <iomanip>
#include  <ctime>
#include  <cstdlib>

using namespace std;

// Globally declared constants for shift and scale
const int SHIFT = 1;
const int SCALE = 6;

// Function prototype for the function to generate a random die result
int getOneDie(void);

int main()
{
	char response = 'Y';
	int die1, die2;

	// Generates the seed to be used for the random number generator
	time_t seed;

	// Fills the seed with the calender time from the system
    time(&seed);

    // Seeds the generator used by the random number function
    srand(seed);

    // Begins loop for user dice rolls
    do
    {
		cout << "Do you want to roll the dice? (Y/N): ";
            cin >> response;

        if(response == 'Y' || response == 'y' || response == 'N' || response == 'n')
        {
			if(response == 'Y' || response == 'y')
			{
				die1 = getOneDie();
				die2 = getOneDie();
				cout << "Values are " << die1 << " and " << die2 << ". Total of die roll is " << die1 + die2 << "." << endl << endl;
			}

			else
			{
				cout << "Hope you enjoyed the game." << endl << endl;
				break;
			}
		}

		else
		{
			cout << "Please enter a Y or N as a response.";
			response = 'Y';
		}
	} while(response == 'Y' || response == 'y');
}

int getOneDie(void)
{
	int dieResult = 0;

	// Generates a random number as the die result
	dieResult = rand();

	// Scales the random number down to 0-5
	dieResult = dieResult % SCALE;

	// Shifts the random number to 1-6
	dieResult = dieResult + SHIFT;

	// Sends back the result from the die roll
	return dieResult;
}

