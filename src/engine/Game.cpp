#include <iostream>
#include <string>

#include "engine/Game.h"
#include "engine/Board.h"
#include "engine/GameTools.h"

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
	if (!checkRules(x, y)) {
		board->getBoard()[x][y] = empty;
		return;
	}

	switchTurn();

}

bool Game::checkRules(int x, int y)
{
	intersection_t** cur = board->getBoard();
	intersection_t type =
		turn == black_turn ? black_stone : white_stone;
	StoneString string;

	if (cur[x][y] != empty) {
		return false;
	}

	switch(turn) {
		case black_turn:
			board->getBoard()[x][y] = black_stone;
			break;
		case white_turn:
			board->getBoard()[x][y] = white_stone;
			break;
		default:
			std::cout << "[Unknown turn_t]" << std::endl;
	}


	GameTools::getString(board, &string, x, y, type);
	int liberties = GameTools::countStringLiberties(board, &string);

	if (liberties == 0) {
		return false;
	}

	return true;
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
