#pragma once

#include "Entity.h"

/*
	L'ensemble des objets inanim�s
*/

class Prop :
	public Entity
{
public:
	Prop(sf::Texture& texture, int x, int y, int w, int h, bool s);
	Prop(sf::Texture& texture, int x, int y, int w, int h, int life);
	~Prop(void);
	
	int lifeGain_get();
	virtual void update();

private:
	bool catchable; //Le joueur peut capturer l'objet dans le gant
	int lifeGain;
};

Prop* newPotion(sf::Texture& texture, int x, int y);