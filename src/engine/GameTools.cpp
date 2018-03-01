#include "engine/GameTools.h"

void GameTools::getString(Board *board, StoneString *tempRes, 
		int x, int y, intersection_t type) 
{
	if (tempRes->contains(x, y)) {
		return;
	}

	if (board->getBoard()[x][y] != type) {
		return;
	}

	std::vector<std::pair<int,int>> *stones = tempRes->getString();
	stones->push_back(std::make_pair(x,y));

	if (x == 0) {
		GameTools::getString(board, tempRes, x+1, y, type);

		if (y == 0) {
			GameTools::getString(board, tempRes, x, y+1, type);
		}
		else if (y == 18) {
			GameTools::getString(board, tempRes, x, y-1, type);
		}
		else {
			GameTools::getString(board, tempRes, x, y+1, type);
			GameTools::getString(board, tempRes, x, y-1, type);
		}
		return;
	}
	else if (x == 18) {
		GameTools::getString(board, tempRes, x-1, y, type);

		if (y == 0) {
			GameTools::getString(board, tempRes, x, y+1, type);
		}
		else if (y == 18) {
			GameTools::getString(board, tempRes, x, y-1, type);
		}
		else {
			GameTools::getString(board, tempRes, x, y+1, type);
			GameTools::getString(board, tempRes, x, y-1, type);
		}
		return;
	}
	else if (y == 0) {
		GameTools::getString(board, tempRes, x, y+1, type);
		GameTools::getString(board, tempRes, x-1, y, type);
		GameTools::getString(board, tempRes, x+1, y, type);
		return;
	}
	else if (y == 18) {
		GameTools::getString(board, tempRes, x, y-1, type);
		GameTools::getString(board, tempRes, x-1, y, type);
		GameTools::getString(board, tempRes, x+1, y, type);
		return;
	}
	else {
		GameTools::getString(board, tempRes, x+1, y, type);
		GameTools::getString(board, tempRes, x-1, y, type);
		GameTools::getString(board, tempRes, x, y+1, type);
		GameTools::getString(board, tempRes, x, y-1, type);
		return;
	}
}

int GameTools::countStringLiberties(Board *board, StoneString *string)
{
	int total = 0;
	for (std::pair<int,int> el : *string->getString()) {
		total += GameTools::countStoneLiberties(board, el.first, el.second);
	}
	return total;
}

int GameTools::countStoneLiberties(Board *board, int x, int y)
{
	int total = 0;

	if (x == 0) {
		if (board->isEmpty(x+1, y)) total++;

		if (y == 0) {
			if (board->isEmpty(x, y+1)) total++;
		}
		else if (y == 18) {
			if (board->isEmpty(x, y-1)) total++;
		}
		else {
			if (board->isEmpty(x, y+1)) total++;
			if (board->isEmpty(x, y-1)) total++;
		}
		return total;
	}
	else if (x == 18) {
		if (board->isEmpty(x-1, y)) total++;

		if (y == 0) {
			if (board->isEmpty(x, y+1)) total++;
		}
		else if (y == 18) {
			if (board->isEmpty(x, y-1)) total++;
		}
		else {
			if (board->isEmpty(x, y+1)) total++;
			if (board->isEmpty(x, y-1)) total++;
		}
		return total;
	}
	else if (y == 0) {
		if (board->isEmpty(x, y+1)) total++;
		if (board->isEmpty(x-1, y)) total++;
		if (board->isEmpty(x+1, y)) total++;
		return total;
	}
	else if (y == 18) {
		if (board->isEmpty(x, y-1)) total++;
		if (board->isEmpty(x-1, y)) total++;
		if (board->isEmpty(x+1, y)) total++;
		return total;
	}
	else {
		if (board->isEmpty(x+1, y)) total++;
		if (board->isEmpty(x-1, y)) total++;
		if (board->isEmpty(x, y+1)) total++;
		if (board->isEmpty(x, y-1)) total++;
		return total;
	}
}
