#include <iostream>

#include "SDL.h"
#include "SDL_error.h"

#include "graphic/Init.h"

void initGraphics()
{
	SDL_Window *win;
	SDL_Renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}

	win = SDL_CreateWindow("Hello GoMoku!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

}
