#include <iostream>

#include "engine/Board.h"
#include "engine/Game.h"

#include "graphic/Init.h"

int main()
{
	initGraphics();
	Board b(19);
	b.printBoard();

	return 0;
}
