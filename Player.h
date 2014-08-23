#pragma once
#include "Entity.h"

class Player :
	public Entity
{
public:
	Player(void);
	~Player(void);

private:
	int life;
};

