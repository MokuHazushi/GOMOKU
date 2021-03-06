#define GL3_PROTOTYPES 1

#include <iostream>

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_image.h"

#include "graphic/Init.h"
#include "graphic/Tools.h"
#include "graphic/Images.h"

MainFrame::MainFrame(Game* _game)
{
	initGraphics();
	game = _game;
	images = new Images(renderer);
	margins = Tools::getMargins(SCREEN_SIZE);
}

MainFrame::~MainFrame()
{
	destroyGraphics();
}

void MainFrame::initGraphics()
{
	int res;

	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("GoMoku",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_SIZE, SCREEN_SIZE,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	res = IMG_Init(IMG_INIT_PNG);
	if ((res & IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cout << "[FAIL] : IMG_Init <" << IMG_GetError() << ">" << std::endl;
	}
}

void MainFrame::destroyGraphics()
{
	delete images;

	SDL_DestroyWindow(win);
	win = NULL;
	
	IMG_Quit();
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
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xAC, 0x33, 0xFF);
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

				if (boardCoord[0] != -11 && boardCoord[1] != -1) {
					game->update(boardCoord[0], boardCoord[1]);
				}
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
	int i,j;
	Board *board = game->getBoard();

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

	for (i=0; i<19; i++) {
		for (j=0; j<19; j++) {
			switch (board->getBoard()[i][j]) {
				case empty:
					continue;
					break;
				case black_stone:
					drawStone(i, j, images->getBlackStone(), stoneSize, margin);
					break;
				case white_stone:
					drawStone(i, j, images->getWhiteStone(), stoneSize, margin);
					break;
				default:
					std::cout << "[Unknown intersection_t]" << std::endl;
			}
		}
	}

	*_margin = margin;
	*_stoneSize = stoneSize;
}

void MainFrame::drawStone(int i, int j, SDL_Texture* stone, int stoneSize, int margin)
{
	SDL_Rect dest;
	dest.x = margin + i*stoneSize - stoneSize/2;
	dest.y = margin + j*stoneSize - stoneSize/2;
	dest.w = stoneSize;
	dest.h = stoneSize;

	SDL_RenderCopy(renderer, stone, NULL, &dest);
}
