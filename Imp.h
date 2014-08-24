#pragma once
#include "mob.h"

class Imp :
	public Mob
{
public:
	Imp(sf::Texture& t, int x, int y);
	~Imp(void);
};

