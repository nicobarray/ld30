#include "Prop.h"

Prop::Prop(sf::Texture& texture, int x, int y, int w, int h, bool s, int teleport)
	: Entity(texture, x, y, w, h, s)
	, lifeGain(0)
	, link(teleport)
{
}

Prop::Prop(sf::Texture& texture, int x, int y, int w, int h, int life)
	: Entity(texture, x, y, w, h, false)
	, lifeGain(life)
	, catchable(false)
	, link(0)
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

Prop* newCrate(sf::Texture& texture, int x, int y)
{
	Prop* p = new Prop(texture, x, y, 32, 32, true);
	return p;
}

int Prop::link_get()
{
	return link;
}