#include <iostream>
#include <utility>

#include "engine/Board.h"

//CONSTRUCTORS DESTRUCTOR

Board::Board(unsigned short s) : size(s)
{
	int i;

	board = new intersection_t*[size];
	for (i=0; i<size; i++) {
		board[i] = new intersection_t[size];
	}

	clearBoard();
}

Board::~Board()
{
	int i;
	for (i=0; i<size; i++) {
		delete[] board[i];
	}
	delete[] board;
}

//METHODS

void Board::clearBoard()
{
	int i, j;

	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			board[i][j] = empty;
		}
	}
}

void Board::printBoard()
{
	int i, j;

	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			std::cout << toString(board[i][j]) << " ";
		}
		std::cout << std::endl;
	}
}

bool Board::isEmpty(int x, int y)
{
	return board[x][y] == empty;
}

//UTILS
//GETTER SETTER

unsigned short Board::getSize()
{
	return size;
}

intersection_t** Board::getBoard()
{
	return board;
}
