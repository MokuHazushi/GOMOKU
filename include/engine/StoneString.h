#include <vector>
#include <string>

#ifndef STONESTRING_H
#define STONESTRING_H

class StoneString {
	private:
		std::vector<std::pair<int, int>> *string;

	public:
		StoneString();
		~StoneString();

		void addStone(int x, int y);
		bool contains(int x, int y);

		std::vector<std::pair<int, int>>* getString() const;

		std::string toString() const;
};

#endif
