#include <string>
#include <vector>

#include "SDL.h"
#include "engine/Game.h"

#ifndef INIT_H
#define INIT_H

#define SCREEN_SIZE 640

class MainFrame {
	private:
		Game *game;

		SDL_Window *win;
		SDL_Surface *screen;
		SDL_Renderer *renderer;

		std::vector<int> margins;

		void initGraphics();
		void destroyGraphics();
		void drawBoard(int*, int*);
	public:
		MainFrame(Game*);
		~MainFrame();

		void startMainLoop();
};

#endif
