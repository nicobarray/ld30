#include "Ressource.h"

SDL_Surface* Ressource::load_image(std::string path)
{
	// load sample.png into image
	SDL_Surface *texture;
	SDL_RWops *rwop;

	rwop = SDL_RWFromFile(path.c_str(), "rb");
	if(!(texture = IMG_LoadPNG_RW(rwop))) {
		std::cerr << "IMG LoadPNG RW: " << IMG_GetError() << std::endl;
	}

	textures.push_back(texture);

	return texture;
}

Ressource::~Ressource(void)
{
	IMG_Quit();
}
