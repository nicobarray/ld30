#include "Prop.h"

Prop::Prop(sf::Texture& texture, int x, int y, int w, int h, bool s, bool teleport)
	: Entity(texture, x, y, w, h, s)
	, statue(teleport)
{
}

Prop::Prop(sf::Texture& texture, int x, int y, int w, int h, int life)
	: Entity(texture, x, y, w, h, false)
	, lifeGain(life)
	, catchable(false)
	, statue(false)
{
}

Prop::~Prop(void)
{
}

int Prop::lifeGain_get()
{
	return lifeGain;
}

void Prop::update()
{
}

Prop* newPotion(sf::Texture& texture, int x, int y)
{
	return new Prop(texture, x, y, 16, 16, 2);
}