#include <vector>

#ifndef STONESTRING_H
#define STONESTRING_H

class StoneString {
	private:
		std::vector<std::pair<int, int>> string;

	public:
		void addStone(int x, int y);
		bool contains(int x, int y);

		std::vector<std::pair<int, int>> getString() const;
};

#endif
