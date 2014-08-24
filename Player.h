#pragma once

#include <SFML\Window\Keyboard.hpp>

#include "Entity.h"

class Player :
	public Entity
{
public:
	Player(sf::Texture& t, int x, int y);
	~Player(void);

	virtual void update() override;

private:
	int life;
	Entity* item;
};

