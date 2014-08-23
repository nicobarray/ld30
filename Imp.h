#pragma once
#include "mob.h"

class Imp :
	public Mob
{
public:
	Imp(SDL_Surface *t, int x, int y, int w, int h);
	~Imp(void);
};

