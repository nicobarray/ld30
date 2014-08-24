#pragma once
#include "mob.h"
class Spitter :
	public Mob
{
public:
	Spitter(sf::Texture& t, Level* l, int x, int y);
	~Spitter(void);

	virtual void update() override;
};

