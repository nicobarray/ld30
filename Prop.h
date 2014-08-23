#pragma once
#include "solidbody.h"

/*
	L'ensemble des objets inanimes
*/

class Prop :
	public SolidBody
{
public:
	Prop(void);
	~Prop(void);

private:
	bool catchable; //Le joueur peut capturer l'objet dans le gant
};

