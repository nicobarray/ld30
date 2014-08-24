#pragma once
#include <math.h>
#include "mob.h"

class Imp :
	public Mob
{
public:
	Imp(sf::Texture& t, Level* l, int x, int y);
	~Imp(void);
	
	virtual void update() override;
};

