#include <iostream>

#include "engine/Board.h"
#include "engine/Game.h"

#include "graphic/Init.h"

int main()
{
	Game *game = new Game(new Board(19), "black", "white");
	MainFrame *frame = new MainFrame(game);
	frame->startMainLoop();
	return 0;
}
