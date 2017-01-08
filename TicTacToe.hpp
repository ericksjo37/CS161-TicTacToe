/*
*Author: Josh Erickson
*Date: 3/1/16
*Description: Header file for the class TicTacToe, a class that allows two people to play a game of tic tac toe.
*/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"

class TicTacToe
{
	private:
		Board Game;
		char player;
	public:
		TicTacToe(char player);
		void play();
};

#endif