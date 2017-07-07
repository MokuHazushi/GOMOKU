#include "SDL.h"

#ifndef INIT_H
#define INIT_H

class MainFrame {
	private:
		SDL_Window *win;
		SDL_GLContext contextOpenGL;

		void initGraphics();
		void destroyGraphics();
	public:
		MainFrame();
		~MainFrame();

		void startMainLoop();
};

#endif
