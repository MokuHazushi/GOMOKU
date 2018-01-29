#include <string>
#include <vector>

#ifndef TOOLS_H
#define TOOLS_H

#define IMAGE_FOLDER "img/"

class Tools {
	public:
		static std::vector<int> getMargins(int);
		static std::string getImagePath(std::string);
		static int* getBoardCoord(int,int,int,int);
};

#endif
