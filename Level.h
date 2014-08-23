#pragma once

#include <vector>

#include "Entity.h"

class Level
{
public:
	Level(int w, int h);
	~Level(void);

	void update();
	void draw(SDL_Surface* screen);

	void addEntity(Entity* e);

private:
	std::vector<std::vector<bool>> ground;
	std::vector<Entity*> items;
};

