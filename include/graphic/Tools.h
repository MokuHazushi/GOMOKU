#include <string>
#include <vector>

#ifndef TOOLS_H
#define TOOLS_H

class Tools {
	public:
		static std::vector<int> getMargins(int);
		static int* getBoardCoord(int,int,int,int);
};

#endif
