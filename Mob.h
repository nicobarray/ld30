#pragma once

#include "Entity.h"
#include "Player.h"
#include "Level.h"

class Mob :
	public Entity
{
public:
	Mob(sf::Texture& t, Level* l, int x, int y, int w, int h);
	~Mob(void);

protected:
	int life;
	Level* parent;
};

