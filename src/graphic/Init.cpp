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
			800, 600,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	screen = SDL_GetWindowSurface(win);
	img = SDL_LoadBMP(getImagePath("test.bmp").c_str());

	SDL_BlitSurface(img, NULL, screen, NULL);
	SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);
}

void MainFrame::destroyGraphics()
{
	SDL_FreeSurface(img);
	img = NULL;

	SDL_DestroyWindow(win);
	win = NULL;
	
	SDL_Quit();
}

void MainFrame::startMainLoop()
{
}

std::string MainFrame::getImagePath(std::string str)
{
	return std::string(IMAGE_FOLDER) + str;
}
