#pragma once
#include "solidbody.h"

class Mob :
	public SolidBody
{
public:
	Mob(void);
	~Mob(void);

private:
	int life;
};

