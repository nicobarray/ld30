#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Entity.h"

class Level
{
public:
	Level(std::string fileName, SDL_Surface* t);
	~Level(void);

	void update();
	void draw(SDL_Surface* screen);

	void addEntity(Entity* e);

private:
	std::vector<std::vector<bool>> ground;
	std::vector<Entity*> items;
	SDL_Surface* tiles;
};

