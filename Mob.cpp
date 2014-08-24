#include "Mob.h"


Mob::Mob(sf::Texture& t, Level* l, int x, int y, int w, int h)
	: Entity(t, x, y, w, h, true)
	, parent(l)
{
}

Mob::~Mob(void)
{
}
