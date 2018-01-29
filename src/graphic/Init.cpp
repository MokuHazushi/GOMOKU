#define GL3_PROTOTYPES 1

#include <iostream>

#include "SDL.h"
#include "SDL_error.h"

#include "graphic/Init.h"
#include "graphic/Tools.h"

MainFrame::MainFrame()
{
	initGraphics();
	margins = Tools::getMargins(SCREEN_SIZE);
}

MainFrame::~MainFrame()
{
	destroyGraphics();
}

void MainFrame::initGraphics()
{
	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("GoMoku",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_SIZE, SCREEN_SIZE,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}

void MainFrame::destroyGraphics()
{
	SDL_DestroyWindow(win);
	win = NULL;
	
	SDL_Quit();
}

void MainFrame::startMainLoop()
{
	bool running = true;
	SDL_Event event;

	while (running) {
		int margin, stoneSize, x, y;
		int *boardCoord;

		//CLEAR BOARD
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		//DRAW BOARD
		drawBoard(&margin, &stoneSize);
		SDL_RenderPresent(renderer);

		//HANDLE EVENT
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&x, &y);
				boardCoord = Tools::getBoardCoord(x, y, margin, stoneSize);
				std::cout << "x: " << boardCoord[0] << " y: " << boardCoord[1] << std::endl;
				delete[] boardCoord;
			}
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_Delay(60);
	}
}

void MainFrame::drawBoard(int *_margin, int *_stoneSize)
{
	int margin = margins[3];
	int stoneSize = (SCREEN_SIZE - 2*margin) / 18;
	int i;

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

	for (i=0; i<19; i++) {
		SDL_RenderDrawLine(renderer, 
				margin,
				i*stoneSize + margin,
				SCREEN_SIZE - margin,
				i*stoneSize + margin);
		SDL_RenderDrawLine(renderer,
				i*stoneSize + margin,
				margin,
				i*stoneSize + margin,
				SCREEN_SIZE - margin);
	}

	*_margin = margin;
	*_stoneSize = stoneSize;
}
