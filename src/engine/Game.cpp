#include <iostream>
#include <string>

#include "engine/Game.h"
#include "engine/Board.h"

//CONSTRUCTORS DESTRUCTOR

Game::Game(Board* brd, std::string pB, std::string pW) :
       board(brd), playerBlack(pB), playerWhite(pW)
{
	turn = black_turn;
}

//METHODS

void Game::switchTurn() {
	switch(turn) {
		case black_turn:
			turn = white_turn;
			return;
		case white_turn:
			turn = black_turn;
			return;
		default:
			std::cout << "[Unknown turn_t]";
	}
}

//GETTER SETTER

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

turn_t Game::getTurn()
{
	return turn;
}
