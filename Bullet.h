#pragma once

#include "prop.h"
#include "Player.h"

class Bullet :
	public Prop
{
public:
	Bullet(sf::Texture& texture, int x, int y);
	~Bullet(void);
	
	virtual void update(std::vector<Entity*> ground, std::vector<Entity*> items) override;
};

