#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<vector>
#include<iostream>

enum tex_id
{
	TILESET1 = 0,
	DROPHEALTH,
	IMP
};

class Ressource
{
public:
	static Ressource& getInstance()
	{
		static Ressource instance;
		return instance;
	}

	~Ressource(void);
	SDL_Surface* load_image(std::string path);
	SDL_Surface* texture_get(int i);

private:
	Ressource(void)
		: textures()
	{
		if (IMG_Init(IMG_INIT_PNG) == 0)
		{
			std::cerr << "IMG Init error: " << IMG_GetError() << std::endl;
		}
	}

	Ressource(Ressource const&);
	void operator=(Ressource const&);

private:
	std::vector<SDL_Surface*> textures;
};

