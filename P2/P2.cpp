//Hickey, Thomas    Matzen    Spring 2014    Program 2
//Overview: An interactive program let two users play a board game
//Compiler Used:  G++ with TextPad editor
//Status:  Compiles and meets the requirements
//Help:  No help

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

// Global named constants for minimum and maximum board sizes
const int BOARD_MIN=3;
const int BOARD_MAX=10;

// Function Prototype for displaying the board
void displayBoard(char [][BOARD_MAX+1], int);

int main()
{

  // 2D array for playing board
  char bd[BOARD_MAX+1][BOARD_MAX+1];

  // Variable for user-chosen board size
  int size;

  // Gets board size from user
  do
  {
      cout << "Enter the size of the board: ";
        cin >> size;

  // Defensive programming message for board size
  if(size > BOARD_MAX || size < BOARD_MIN)
    cout << "Invalid board size" << endl;

  } while(size > BOARD_MAX || size < BOARD_MIN);

  // Initializes playing board
  for(int row = 1; row <= size; row++)
  {
	  for(int col = 1; col <= size; col++)
	  {
		  bd[row][col] = '-';
	  }
  }

  // Declares player position choice variables and accumulator for turn counter
  int p1row, p1col, p2row, p2col, acc=0;

  // Named constant for maximum turns
  const int TURNS_MAX = size * size;

  // Declares player symbol choice variables
  char p1symbol, p2symbol;

  // Declares a flag variableS for defensive programming
  bool p1flag=0, p2flag=0;

  do
  {
    // Displays the play board for player one
    displayBoard(bd, size);

    // Gets player one play choices with defensive programming
    do
    {
		do
		{
			cout << "Player 1 enter your position to play (row - column): ";
              cin >> p1row >> p1col;

            if(p1row > size || p1row < 1)
              cout << endl << "Invalid row.  Please choose a number between 1 and " << size
                   << "." << endl << endl;

            if(p1col > size || p1col < 1)
              cout << endl << "Invalid column.  Please choose a number between 1 and " << size
                   << "." << endl << endl;

		} while(p1row > size || p1row < 1 || p1col > size || p1col < 1);

		do
		{
			cout << "Enter your symbol (R, P, S, or Q to Quit): ";
              cin >> p1symbol;
            cout << endl;

            if(p1symbol == 'Q' || p1symbol == 'q' || p1symbol == 'R' || p1symbol == 'P' || p1symbol == 'S')
              p1flag=1;

            else
              cout << "Invalid play choice!  Please try again." << endl << endl;

		} while(p1flag==0);

        // Checks for player one quit choice
        if(p1symbol == 'Q' || p1symbol == 'q')
        {
			cout << endl << "Game Over! Player 1 forfeits. Thanks for playing" << endl << endl;
			exit(0);
		}

        if(bd[p1row][p1col] != '-')
        {
	  	    cout << "That space is already occupied! Please try again." << endl;
		    displayBoard(bd, size);
	    }

    } while(bd[p1row][p1col] != '-');

    // Modifies the play board and resets the flag for player one and increases the turn counter
    bd[p1row][p1col] = p1symbol;
    p1flag=0;
    acc++;

    // Checks for full board
    if(acc >= TURNS_MAX)
    {
		displayBoard(bd, size);
		cout << endl << "Game Over! Thanks for playing" << endl << endl;
		exit(0);
	}

    // Displays the play board for player two
    displayBoard(bd, size);

    // Gets player two play choices with defensive programming
    do
    {
		do
		{
			cout << "Player 2 enter your position to play (row - column): ";
              cin >> p2row >> p2col;

            if(p2row > size || p2row < 1)
              cout << endl << "Invalid row.  Please choose a number between 1 and " << size
                   << "." << endl << endl;

            if(p2col > size || p2col < 1)
              cout << endl << "Invalid column.  Please choose a number between 1 and " << size
                   << "." << endl << endl;

		} while(p2row > size || p2row < 1 || p2col > size || p2col < 1);

		do
		{
			cout << "Enter your symbol (r, p, s or q to quit): ";
              cin >> p2symbol;
            cout << endl;

            if(p2symbol == 'Q' || p2symbol == 'q' || p2symbol == 'r' || p2symbol == 'p' || p2symbol == 's')
              p2flag=1;

            else
              cout << "Invalid play choice!  Please try again." << endl << endl;

		} while(p2flag==0);

		// Checks for player two quit choice
        if(p2symbol == 'Q' || p2symbol == 'q')
        {
			cout << endl << "Game Over! Player 2 forfeits. Thanks for playing" << endl << endl;
			exit(0);
		}

        if(bd[p2row][p2col] != '-')
        {
	  	    cout << "That space is already occupied! Please try again." << endl << endl;
		    displayBoard(bd, size);
	    }

    } while(bd[p2row][p2col] != '-');

    // Modifies the play board and resets the flag for player two and increases the turn counter
    bd[p2row][p2col] = p2symbol;
    p2flag=0;
    acc++;

  } while(acc <= TURNS_MAX);

  displayBoard(bd, size);
  cout << endl << "Game Over! Thanks for playing" << endl << endl;
}

// Function used to display the current play board
void displayBoard(char bd[][BOARD_MAX+1], int size)
{
	for(int row = 1; row <= size; row++)
	{
		for(int col = 1; col <= size; col++)
		{
			cout << bd[row][col] << " ";
		}

		cout << endl;
    }
}