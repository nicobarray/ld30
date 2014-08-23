#pragma once
#include "Entity.h"

class Player :
	public Entity
{
public:
	Player(SDL_Surface *t, int x, int y, int w, int h);
	~Player(void);

private:
	int life;
	Entity* item;
};

