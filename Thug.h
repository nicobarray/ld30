#pragma once
#include "mob.h"
class Thug :
	public Mob
{
public:
	Thug(sf::Texture& t, Level* l, int x, int y);
	~Thug(void);
	
	virtual void update() override;
};

