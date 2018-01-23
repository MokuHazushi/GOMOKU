#define GL3_PROTOTYPES 1

#include <iostream>

#include "SDL.h"
#include "SDL_error.h"

#include "graphic/Init.h"

MainFrame::MainFrame()
{
	initGraphics();
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
		//CLEAR BOARD
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		//DRAW BOARD
		drawBoard();
		SDL_RenderPresent(renderer);

		//HANDLE EVENT
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_Delay(60);
	}
}

void MainFrame::drawBoard()
{
	int marginFactor = 14;
	int stoneSize = ((marginFactor - 2) * SCREEN_SIZE / marginFactor) / 19;
	int i;

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

	for (i=0; i<19; i++) {
		SDL_RenderDrawLine(renderer, 
				SCREEN_SIZE / marginFactor,
				i*stoneSize + (SCREEN_SIZE / marginFactor),
				(marginFactor-1) * SCREEN_SIZE / marginFactor,
				i*stoneSize + (SCREEN_SIZE / marginFactor));
		SDL_RenderDrawLine(renderer,
				i*stoneSize + (SCREEN_SIZE / marginFactor),
				SCREEN_SIZE / marginFactor,
				i*stoneSize + (SCREEN_SIZE / marginFactor),
				(marginFactor-1) * SCREEN_SIZE / marginFactor);
	}
}

std::string MainFrame::getImagePath(std::string str)
{
	return std::string(IMAGE_FOLDER) + str;
}
