#include "engine/Board.h"

Board::Board(unsigned short s) : size(s) {}

unsigned short Board::getSize()
{
	return size;
}
