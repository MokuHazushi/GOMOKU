#include <iostream>

#include "graphic/Images.h"

Images::Images(SDL_Renderer *_renderer) :
	renderer(_renderer)
{
	loadImages();
}

Images::~Images()
{
}

void Images::loadImages()
{
	SDL_Surface *img_bs = IMG_Load(BLACK_STONE_IMG);
	SDL_Surface *img_ws = IMG_Load(WHITE_STONE_IMG);

	if (img_bs == NULL || img_ws == NULL) {
		std::cout << "[FAIL] : IMG_Load <" << BLACK_STONE_IMG
			<< ";" << WHITE_STONE_IMG << ">" << std::endl;
		std::cout << IMG_GetError() << std::endl;
	}

	black_stone = SDL_CreateTextureFromSurface(renderer, img_bs);
	white_stone = SDL_CreateTextureFromSurface(renderer, img_ws);

	SDL_FreeSurface(img_bs);
	SDL_FreeSurface(img_ws);
}

SDL_Texture* Images::getBlackStone() const
{
	return black_stone;
}

SDL_Texture* Images::getWhiteStone() const
{
	return white_stone;
}
