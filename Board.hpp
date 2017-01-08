/*
*Author: Josh Erickson
*Date: 3/1/16
*Description: Header file for the class Board, containing the constructors for a 3x3 array representing a tic tac toe board.
*/

#ifndef BOARD_HPP
#define BOARD_HPP

//Enumerated type gameState, 1= X_WON, 2= O_WON, 3= DRAW, 4= UNFINISHED
enum gameState {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
	private:
		static const int boardRow = 3, boardCol = 3;
		char board[boardRow][boardCol]; //3x3 array of characters to hold the board
		char winner;
		int turn;
	public:
		Board(); //Default constructor to initialize the 3x3 array to being empty
		bool makeMove(int row, int col, char player); //Method that takes the y and x coordinates of the move specified by the player and records the move
		int gameState(); //Method that takes no parameters, checks the board for the win conditions, and returns the relevant enum gameState
		void print(); //Method that prints the current board to the screen

};

#endif