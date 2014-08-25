#pragma once

#include "mob.h"
#include "Bullet.h"

class Spitter :
	public Mob
{
public:
	Spitter(sf::Texture& t, Level* l, int x, int y);
	~Spitter(void);

	virtual void update() override;
	virtual void update(std::vector<Entity*> ground, std::vector<Entity*> items) override;
	virtual void draw(sf::RenderWindow& window) override;

	void shoot();

private:
	std::vector<Entity*> shots;
};

