#pragma once
#include "Entity.h"

class Player :
	public Entity
{
public:
	Player(sf::Texture& t, int x, int y);
	~Player(void);

private:
	int life;
	Entity* item;
};

