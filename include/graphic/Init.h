#include <string>
#include <vector>

#include "SDL.h"

#ifndef INIT_H
#define INIT_H

#define IMAGE_FOLDER "img/"

#define SCREEN_SIZE 640

class MainFrame {
	private:
		SDL_Window *win;
		SDL_Surface *screen;
		SDL_Renderer *renderer;

		std::vector<int> margins;

		void initGraphics();
		void destroyGraphics();
		void drawBoard();
		std::string getImagePath(std::string);
	public:
		MainFrame();
		~MainFrame();

		void startMainLoop();
};

#endif
