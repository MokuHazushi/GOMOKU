#include <utility>

#include "engine/StoneString.h"

void StoneString::addStone(int x, int y)
{
	string.push_back(std::make_pair(x,y));
}

bool StoneString::contains(int x, int y)
{
	for (std::pair<int,int> el : string)
	{
		if (el.first == x && el.second == y) {
			return true;
		}
	}

	return false;
}

std::vector<std::pair<int, int>> StoneString::getString() const {
	return string;
}
