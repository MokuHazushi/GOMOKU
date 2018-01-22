#include <string>

#include "SDL.h"

#ifndef INIT_H
#define INIT_H

#define IMAGE_FOLDER "img/"

class MainFrame {
	private:
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;

		SDL_Window *win;
		SDL_Surface *screen;
		SDL_Surface *img;

		void initGraphics();
		void destroyGraphics();
		std::string getImagePath(std::string);
	public:
		MainFrame();
		~MainFrame();

		void startMainLoop();
};

#endif
