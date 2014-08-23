#include "Level.h"


Level::Level(int w, int h)
	: ground(), items()
{
	for (int i = 0; i < w; i++)
	{
		ground.push_back(std::vector<bool>());
		for (int j = 0; j < h; j++)
		{
			ground[i].push_back(true);
		}
	}
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