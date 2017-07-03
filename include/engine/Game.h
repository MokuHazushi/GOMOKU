#include <string>

#include "engine/Board.h"

#ifndef GAME_H
#define GAME_H

enum turn_t {
	black_turn,
	white_turn
};

class Game {
	private:
		Board* board;
		std::string playerBlack;
		std::string playerWhite;
		turn_t turn;
	public:
		Game(Board*, std::string, std::string);

		void startGame();
		void switchTurn();

		Board* getBoard();
		std::string getPlayerBlack();
		std::string getPlayerWhite();
		turn_t getTurn();
};

#endif
