#pragma once
#include "entity.h"

/*
	Represente les entites sans corps physiques
*/

class LightBody :
	public Entity
{
public:
	LightBody(void);
	~LightBody(void);
};

