#include <string>

#include "engine/Board.h"

#ifndef GAME_H
#define GAME_H

class Game {
	private:
		Board* board;
		std::string playerBlack;
		std::string playerWhite;
	public:
		Game(Board*, std::string, std::string);
		Board* getBoard();
		std::string getPlayerBlack();
		std::string getPlayerWhite();
};

#endif
