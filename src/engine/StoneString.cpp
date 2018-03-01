#include <iostream>
#include <utility>

#include "engine/StoneString.h"

StoneString::StoneString()
{
	string = new std::vector<std::pair<int, int>>();
}

StoneString::~StoneString()
{
	delete string;
}

void StoneString::addStone(int x, int y)
{
	string->push_back(std::make_pair(x,y));
}

bool StoneString::contains(int x, int y)
{
	for (std::pair<int,int> el : *string) {
		if (el.first == x && el.second == y) {
			return true;
		}
	}

	return false;
}

std::vector<std::pair<int,int>>* StoneString::getString() const {
	return string;
}

std::string StoneString::toString() const {
	std::string res = "";

	for (std::pair<int, int> el : *string) {
		std::string x = std::to_string(el.first);
		std::string y = std::to_string(el.second);
		res += "(" + x + ";" + y + ") ";
	}

	return res;
}
