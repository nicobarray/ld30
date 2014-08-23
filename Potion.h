#pragma once
#include "prop.h"
class Potion :
	public Prop
{
public:
	Potion(SDL_Surface* texture, int x, int y, int w, int h, bool s);
	~Potion(void);
};

