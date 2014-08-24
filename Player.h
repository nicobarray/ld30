#pragma once

#include <SFML\Window\Keyboard.hpp>

#include "Entity.h"
#include "Prop.h"

class Player :
	public Entity
{
public:
	Player(sf::Texture& t, int x, int y);
	~Player(void);

	virtual void update() override;
	virtual void update(std::vector<Entity*> ground, std::vector<Entity*> items) override;

	virtual void die(int n) override;

private:
	int life;
	Entity* item;
};

