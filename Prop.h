#pragma once

#include "Entity.h"

/*
	L'ensemble des objets inanimés
*/

class Prop :
	public Entity
{
public:
	Prop(sf::Texture& texture, int x, int y, int w, int h, bool s, int link = 0);
	Prop(sf::Texture& texture, int x, int y, int w, int h, int life);
	~Prop(void);
	
	int lifeGain_get();
	virtual void update();

	int link_get();

private:
	bool catchable; //Le joueur peut capturer l'objet dans le gant
	int lifeGain, link;
};

Prop* newPotion(sf::Texture& texture, int x, int y);
Prop* newCrate(sf::Texture& texture, int x, int y);