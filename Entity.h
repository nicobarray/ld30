#pragma once

#include "SDL.h"

/*
	Classe abstraite
	Represente tous les objets/creatures/drops
*/

class Entity
{
public:
	Entity(void);
	~Entity(void);

	void location_set(int x, int y, int w, int h);
	void texture_set(SDL_Surface* tex);
	
	virtual void update() = 0;
	virtual void draw(SDL_Surface* screen) = 0;

private:
	SDL_Rect* location;
	SDL_Surface* texture;
};

