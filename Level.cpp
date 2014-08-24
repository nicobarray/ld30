#include "Level.h"

Level::Level(std::string fileName, sf::Texture& tileset)
	: ground()
	, items()
	, tileset(tileset)
{

}

Level::~Level(void)
{
	for(Entity* var : items)
		delete var;
}

std::vector<std::vector<bool>>& Level::ground_get()
{
	return ground;
}
std::vector<Entity*>& Level::items_get()
{
	return items;
}

void Level::update()
{
	for(Entity* var : items)
		var->update();
	for(Entity* var : items)
		var->update(items);
}

void Level::draw(sf::RenderWindow& window)
{
	for(Entity* var : items)
		var->draw(window);
}

void Level::addEntity(Entity* e)
{
	items.push_back(e);
}