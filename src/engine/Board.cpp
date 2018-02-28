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

//UTILS
void Board::getString(StoneString *tempRes, int x, int y, intersection_t type) 
{
	if (tempRes->contains(x, y)) {
		return;
	}

	if (board[x][y] != type) {
		return;
	}

	std::vector<std::pair<int,int>> stones = tempRes->getString();
	stones.push_back(std::make_pair(x,y));

	if (x == 0) {
		getString(tempRes, x+1, y, type);

		if (y == 0) {
			getString(tempRes, x, y+1, type);
		}
		else if (y == 18) {
			getString(tempRes, x, y-1, type);
		}
		else {
			getString(tempRes, x, y+1, type);
			getString(tempRes, x, y-1, type);
		}
		return;
	}
	else if (x == 18) {
		getString(tempRes, x-1, y, type);

		if (y == 0) {
			getString(tempRes, x, y+1, type);
		}
		else if (y == 18) {
			getString(tempRes, x, y-1, type);
		}
		else {
			getString(tempRes, x, y+1, type);
			getString(tempRes, x, y-1, type);
		}
		return;
	}
	else if (y == 0) {
		getString(tempRes, x, y+1, type);
		getString(tempRes, x-1, y, type);
		getString(tempRes, x+1, y, type);
		return;
	}
	else if (y == 18) {
		getString(tempRes, x, y-1, type);
		getString(tempRes, x-1, y, type);
		getString(tempRes, x+1, y, type);
		return;
	}
	else {
		getString(tempRes, x+1, y, type);
		getString(tempRes, x-1, y, type);
		getString(tempRes, x, y+1, type);
		getString(tempRes, x, y-1, type);
		return;
	}
}

//GETTER SETTER

unsigned short Board::getSize()
{
	return size;
}

intersection_t** Board::getBoard()
{
	return board;
}
