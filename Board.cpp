/*
*Author: Josh Erickson
*Date: 3/1/16
*Description: Source file for the class Board, containing the constructors for a 3x3 array representing a tic tac toe board.
*/

#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board()	//Default constructor to initialize the 3x3 array to being empty (empty meaning full of ".")
{
	int turn = 0;
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = '.';
}

bool Board::makeMove(int row, int col, char player) //Method that takes the y and x coordinates of the move specified by the player and records the move
{
	if (board[row][col] == '.') //If the coordinates that are input are not taken
	{						
		board[row][col] = player;//then record the move
		return true;		//and return true
	}
	else
		return false;		//otherwise, return false. (if the coordinates are occupied by anything other than '.')
}

int Board::gameState() //Method that takes no parameters, checks the board for the win conditions, and returns the relevant enum gameState
{
	turn++;	//Increment the number of turns having occurred
	//These are the 8 possible win conditions
	if ((board[0][0] == 'x' || board[0][0] == 'o') && (board[0][0] == board[0][1] && board[0][0] == board[0][2]))
	{
		winner = board[0][0];
	}
	else if ((board[1][0] == 'x' || board[1][0] == 'o') && (board[1][0] == board[1][1]) && (board[1][0] == board[1][2]))
	{
		winner = board[1][0];
	}
	else if ((board[2][0] == 'x' || board[2][0] == 'o') && (board[2][0] == board[2][1]) && (board[2][0] == board[2][2]))
	{
		winner = board[2][0];
	}
	else if ((board[0][0] == 'x' || board[0][0] == 'o') && (board[0][0] == board[1][0]) && (board[0][0] == board[2][0]))
	{
		winner = board[0][0];
	}
	else if ((board[0][1] == 'x' || board[0][1] == 'o') && (board[0][1] == board[1][1]) && (board[0][1] == board[2][1]))
	{
		winner = board[0][1];
	}
	else if ((board[0][2] == 'x' || board[0][2] == 'o') && (board[0][2] == board[1][2]) && (board[0][2] == board[2][2]))
	{
		winner = board[0][2];
	}
	else if ((board[0][0] == 'x' || board[0][0] == 'o') && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
	{
		winner = board[0][0];
	}
	else if ((board[2][0] == 'x' || board[2][0] == 'o') && (board[2][0] == board[1][1]) && (board[2][0] == board[0][2]))
	{
		winner = board[2][0];
	}
	if (turn == 10) //If the game reaches 10 turns, it's a draw and the 10th turn should not be taken.
	{
		return DRAW; //In which case the game would be a draw, so return enum DRAW
	}
	if (winner == 'x')	//If the winner of the game was player x,
	{
		return X_WON;	//then return enum X_WON
	}
	if (winner == 'o')	//If the winner of the game was player o,
	{
		return O_WON;	//then return enum O_WON
	}
	else return UNFINISHED; //Return UNFINISHED enum if the game has not been finished in a draw or won.

}

void Board::print()
{
	cout << endl;
	cout << " ";
	for (int colNum = 0; colNum < 3; colNum++) //This for loop will list the column numbers 0 1 2
	{
		cout << " " << colNum;
	};
	cout << "\n" << endl;
	for (int row = 0; row < 3; row++)	//for loop to keep track of what row we're in
		for (int col = 0; col < 3; col++) //for loop to keep track of what column we're in
		{
			if (col == 0)			//If we're starting a new row,
			{
				cout << row << " ";	//output that row number
			};
			cout << board[row][col] << " "; //Then display the contents of that row
			if (col == 2)		//Once all the contents of that row have been displayed (0-2),
			{
				cout << endl;	//End that row and start the next
				cout << endl;
			}

		}
}