#include "Potion.h"


Potion::Potion(SDL_Surface* texture, int x, int y, int w, int h, bool s)
	:Entity(texture, x, y, w, h, s)
{
}


Potion::~Potion(void)
{
}
