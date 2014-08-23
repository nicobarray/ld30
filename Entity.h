#pragma once

#include <vector>

#include "Box.h"
#include "SDL.h"

/*
	Classe abstraite
	Represente tous les objets/creatures/drops
*/

class Entity
{
public:
	Entity(SDL_Surface* t, int x, int y);
	virtual ~Entity(void);

	void location_set(int x, int y, int w, int h);
	void texture_set(SDL_Surface* tex);
	
	void update();
	void update(std::vector<Entity*>);
	void draw(SDL_Surface* screen);

	bool contact(Entity *e);
	void move(int x, int y);
	void move();
	void moveBack();

private:
	SDL_Rect* location;
	SDL_Surface* texture;
	bool solid;
	Box b;
	int move_x, move_y;
};

