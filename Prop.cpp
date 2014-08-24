#include "Prop.h"

Prop::Prop(sf::Texture& texture, int x, int y, int w, int h, bool s)
	: Entity(texture, x, y, w, h, s)
{
}

Prop::Prop(sf::Texture& texture, int x, int y, int w, int h, int life)
	: Entity(texture, x, y, w, h, false)
	, lifeGain(life)
	, catchable(false)
{
}

Prop::~Prop(void)
{
}

int Prop::lifeGain_get()
{
	return lifeGain;
}

Prop* newPotion(sf::Texture& texture, int x, int y)
{
	return new Prop(texture, x, y, 16, 16, 2);
}