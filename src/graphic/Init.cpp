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
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}

	win = SDL_CreateWindow("GoMoku", 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			800, 600, 
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	contextOpenGL = SDL_GL_CreateContext(win);

	if (contextOpenGL == 0) {
		std::cout << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(win);
		SDL_Quit();
	}

}

void MainFrame::destroyGraphics()
{
	SDL_GL_DeleteContext(contextOpenGL);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void MainFrame::startMainLoop()
{
	bool running;
	SDL_Event events;

	running = true;
	while (running) {
		SDL_WaitEvent(&events);
		if (events.window.event == SDL_WINDOWEVENT_CLOSE) {
			running = false;
		}
	}

	destroyGaphics();
}
