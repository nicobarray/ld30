#pragma once
#include "Entity.h"

/*
	L'ensemble des objets inanimes
*/

class Prop :
	public Entity
{
public:
	Prop(SDL_Surface* texture, int x, int y);
	~Prop(void);

private:
	bool catchable; //Le joueur peut capturer l'objet dans le gant
};

