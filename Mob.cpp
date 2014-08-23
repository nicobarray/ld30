#include "Mob.h"


Mob::Mob(SDL_Surface *t, int x, int y)
{
	texture_set(t);
	location_set(x, y, t->w, t->h);
}


Mob::~Mob(void)
{
}
