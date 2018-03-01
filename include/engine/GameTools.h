#include "engine/Board.h"
#include "engine/StoneString.h"

#ifndef GAMETOOLS_H
#define GAMETOOLS_H

class GameTools {
	private:
		static int countStoneLiberties(Board *board, int x, int y);
	public:
		static void getString(Board *board, StoneString *res, 
				int x, int y, intersection_t type);
		static int countStringLiberties(Board *board, StoneString *string);
};

#endif
