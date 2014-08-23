#include "Level.h"

Level::Level(std::string fileName, SDL_Surface* tileset)
	: ground()
	, items()
	, tiles(tileset)
{
	
}

Level::~Level(void)
{
	for(Entity* var : items)
		delete var;
}

void Level::update()
{
	for(Entity* var : items)
		var->update();
	for(Entity* var : items)
		var->update(items);
}

void Level::draw(SDL_Surface* screen)
{
	for(Entity* var : items)
		var->draw(screen);
}

void Level::addEntity(Entity* e)
{
	items.push_back(e);
}