#pragma once
#include "Entity.h"

class Mob :
	public Entity
{
public:
	Mob(sf::Texture& t, int x, int y, int w, int h);
	~Mob(void);

private:
	int life;
};

