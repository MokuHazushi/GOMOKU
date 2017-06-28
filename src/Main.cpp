#include <iostream>

#include "engine/Board.h"
#include "engine/Game.h"

#include "graphic/Test.h"

int main()
{
	std::cout << "Hello World!" << std::endl;
	Board b(9);
	std::cout << b.getSize() << std::endl;
	graphicTest();

	Game g(&b, "player1", "player2");
	std::cout << g.getBoard()->getSize() << std::endl;
	std::cout << g.getPlayerBlack() << std::endl;
	return 0;
}
