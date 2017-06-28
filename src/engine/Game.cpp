#include <string>

#include "engine/Game.h"
#include "engine/Board.h"

Game::Game(Board* brd, std::string pB, std::string pW) :
       board(brd), playerBlack(pB), playerWhite(pW) {}	

Board* Game::getBoard()
{
	return board;
}

std::string Game::getPlayerBlack()
{
	return playerBlack;
}

std::string Game::getPlayerWhite()
{
	return playerWhite;
}
