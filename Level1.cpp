#include "Level1.h"

Level1::Level1(sf::Texture& real_world, sf::Texture& fairy_world)
	: Level("map/level1.tmx", real_world, fairy_world)
{
	addEntity(new Prop(Ressource::getInstance().texture_get((int)TILESET2), 16 * 2, 16 * 2, 16, 16, true)); 
}

Level1::~Level1(void)
{
}
