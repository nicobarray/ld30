#pragma once
#include "Entity.h"

class Mob :
	public Entity
{
public:
	Mob(SDL_Surface* t, int x, int y, int w, int h);
	~Mob(void);

private:
	int life;
};

