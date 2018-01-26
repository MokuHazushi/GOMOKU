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
