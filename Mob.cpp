#include "Mob.h"


Mob::Mob(SDL_Surface *t, int x, int y, int w, int h)
	: Entity(t, x, y, w, h, false)
{
}


Mob::~Mob(void)
{
}
