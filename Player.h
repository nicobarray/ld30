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

	virtual void hurt(int n) override;

	sf::View& view_get();

	int life_get();
	int max_life_get();

	int glove_get();
	int max_glove_get();

private:
	int life, max_life;
	int glove, max_glove;
	Entity* item;
	sf::View view;
};

