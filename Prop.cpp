#include "Prop.h"

Prop::Prop(SDL_Surface* texture, int x, int y, int w, int h, bool s)
	: Entity(texture, x, y, w, h, s)

{
}

Prop::Prop(SDL_Surface* texture, int x, int y, int w, int h, int life)
	: Entity(texture, x, y, w, h, false)
	, lifeGain(life)
	, catchable(false)
{
}

Prop::~Prop(void)
{
}

Prop* newPotion(SDL_Surface* texture, int x, int y)
{
	return new Prop(texture, x, y, 48, 48, 2);
}