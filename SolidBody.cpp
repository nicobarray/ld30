#include "SolidBody.h"


SolidBody::SolidBody(void)
{
}


SolidBody::~SolidBody(void)
{
}

template bool SolidBody::collide<>(SolidBody *e)
{
	return true;
}