#pragma once

#include "Scene.h"
#include "Level.h"
#include "Ressource.h"

#include "AllEntities.h"

class TestRoom : public Scene
{
public:
	TestRoom();
	TestRoom(sf::Texture& tileset);
	virtual ~TestRoom();

	virtual void transition_in();
	virtual void transition_out();
	virtual void update(sf::Event& e, int index);
	virtual void draw(sf::RenderWindow& window);

private:
	Level level;
};

