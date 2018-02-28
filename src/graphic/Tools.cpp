#define GL3_PROTOTYPES 1

#include <iostream>
#include <vector>

#include "graphic/Tools.h"

std::vector<int> Tools::getMargins(int size)
{
	std::vector<int> res;
	int margin = 0;
	int k = size -2*margin;

	while (k >= 0) {
		if (k % 18 == 0) {
			res.push_back(margin);
		}
		margin++;
		k = size - 2*margin;
	} 

	std::cout << "Available margins : {";
	for (int m : res) {
		std::cout << m << ";";
	}
	std::cout << "}" << std::endl;

	return res;
}

int* Tools::getBoardCoord(int x, int y, int margin, int stoneSize)
{
	int *res = new int[2];
	int error = stoneSize / 2;
	int i, j;

	if (x < margin-error ||
			x > margin+error+18*stoneSize ||
			y < margin-error ||
			y > margin+error+18*stoneSize) {
		res[0] = -1;
		res[1] = -1;
		return res;
	}

	for (i=0; i<18; i++) {
		if (x < margin+error+i*stoneSize &&
				x > margin-error+i*stoneSize)
			break;
	}

	for (j=0; j<18; j++) {
		if (y < margin+error+j*stoneSize &&
				y > margin-error+j*stoneSize)
			break;
	}

	res[0] = i;
	res[1] = j;
	return res;
}
