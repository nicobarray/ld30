#pragma once

#include "Entity.h"

class SolidBody: Entity
{
public:
	SolidBody(void);
	~SolidBody(void);

	template<typename T> bool collide(T *e);
};

template<typename T> bool collide(T *e)
{
	return false;
}

template bool SolidBody::collide<>(SolidBody *e);

