#include <iostream>

#include "engine/StoneString.h"

#ifndef BOARD_H
#define BOARD_H

enum intersection_t {
	black_stone,
	white_stone,
	empty
};

inline const std::string toString(intersection_t i)
{
	switch (i) {
		case black_stone: return "B";
		case white_stone: return "W";
		case empty: return "x";
		default: return "[Unknown intersection_t]";
	}
}

class Board {
	private:
		unsigned short size;
		intersection_t** board;
	public:
		Board(unsigned short);
		~Board();

		void clearBoard();
		void printBoard();
		bool isEmpty(int x, int y);

		unsigned short getSize();
		intersection_t** getBoard();
};

#endif
