#pragma once

#include "Box.h"
#include "SDL.h"

/*
	Classe abstraite
	Represente tous les objets/creatures/drops
*/

class Entity
{
public:
	Entity(void);
	virtual ~Entity(void);

	void location_set(int x, int y, int w, int h);
	void texture_set(SDL_Surface* tex);
	
	virtual void update() = 0;
	virtual void draw(SDL_Surface* screen);

	bool contact(Entity *e);

private:
	SDL_Rect* location;
	SDL_Surface* texture;
	bool solid;
	Box b;
};

