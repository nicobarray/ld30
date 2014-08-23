#pragma once
#include "Entity.h"

class Mob :
	public Entity
{
public:
	Mob(void);
	~Mob(void);

private:
	int life;
};

