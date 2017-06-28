#include <iostream>
#include "engine/Board.h"
#include "graphic/Test.h"

int main()
{
	std::cout << "Hello World!" << std::endl;
	Board b(9);
	std::cout << b.getSize() << std::endl;
	graphicTest();
	return 0;
}
