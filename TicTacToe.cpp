/*
*Author: Josh Erickson
*Date: 3/1/16
*Description: Source file for the class TicTacToe, a class that allows two people to play a game of tic tac toe.
*/

#include <iostream>
#include "TicTacToe.hpp"

using namespace std;

TicTacToe::TicTacToe(char firstPlayer)
{
	player = firstPlayer;
}

void TicTacToe::play()
{
	int gameState = Game.gameState(); //Define an integer to hold the enum state relevant to the game, will hold some number 1-4.
	int row; //Rows
	int col; //Columns
	char playerUpper; //Character to mirror the player character, just uppercase

	do	//Do while loop that will continue as long as gameState is UNFINISHED
	{
		playerUpper = toupper(player); //To convert the player x or player o to uppercase to match the example text.
		cout << "Player " << playerUpper << ": please enter your move." << endl;
		Game.print(); //Print the board
		cin >> row >> col;	//Accept the player coordinates for the board
		cout << endl;
		if (Game.makeMove(row, col, player)) //makeMove returns a true/false here as it is a bool function.
		{
			gameState = Game.gameState(); //Will return the updated enum value based on the new array values
			if (player == 'x')
			{
				player = 'o';	//Swap the players turns
			}
			else
				player = 'x';
		}
		else
		{
			cout << "That square is already taken" << endl << endl;
		}
	} while (gameState == UNFINISHED);
	if (gameState == X_WON)
	{
		Game.print();
		cout << "Player X won." << endl;
	}
	else if (gameState == O_WON)
	{
		Game.print();
		cout << "Player O won." << endl;
	}
	else if (gameState == DRAW)
	{
		Game.print();
		cout << "Game is a draw." << endl;
	}
}

int main()
{
	char player;
	cout << "Which player should go first? X or O?" << endl;
	cin >> player;
	while (player != 'x' && player != 'o')
	{
			cout << "Input must be x or o, please specifiy which player should go first.\n";
			cin >> player;
	}
	
	if (player == 'x' || player == 'o')
	{
		TicTacToe Game(player);

		Game.play();
	}
	return 0;
}


