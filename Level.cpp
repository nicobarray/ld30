#include "Level.h"


Level::Level(void)
	: ground(), items()
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
}

void Level::draw()
{
	for(Entity* var : items)
		var->draw();
}

void Level::addEntity(Entity* e)
{
	items.push_back(e);
}