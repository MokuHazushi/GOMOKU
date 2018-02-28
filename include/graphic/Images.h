#define GL3_PROTOTYPES 1

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_image.h"

#ifndef IMAGES_H
#define IMAGES_H

#define IMAGE_FOLDER "img/"

#define BLACK_STONE_IMG	IMAGE_FOLDER "black_stone.png"
#define WHITE_STONE_IMG IMAGE_FOLDER "white_stone.png"

class Images {
	private:
		SDL_Renderer *renderer;
		SDL_Texture *black_stone;
		SDL_Texture *white_stone;

		void loadImages();
	public:
		Images(SDL_Renderer *renderer);
		~Images();

		SDL_Texture *getBlackStone() const;
		SDL_Texture *getWhiteStone() const;
};

#endif
