#pragma once
#include "solidbody.h"

class Player :
	public SolidBody
{
public:
	Player(void);
	~Player(void);

private:
	int life;
};

