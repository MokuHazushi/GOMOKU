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

void Game::startGame()
{
}

void Game::switchTurn()
{
	switch(turn) {
		case black_turn:
			turn = white_turn;
			return;
		case white_turn:
			turn = black_turn;
			return;
		default:
			std::cout << "[Unknown turn_t]" << std::endl;
	}
}

void Game::update(int x, int y)
{
	switch(turn) {
		case black_turn:
			board->getBoard()[x][y] = black_stone;
			switchTurn();
			return;
		case white_turn:
			board->getBoard()[x][y] = white_stone;
			switchTurn();
			return;
		default:
			std::cout << "[Unknown turn_t]" << std::endl;
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
