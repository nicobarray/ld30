#pragma once

#include <SFML\Graphics.hpp>

class Scene
{
public:
	Scene(void);
	virtual ~Scene(void) = 0;
	virtual void transition_in() = 0;
	virtual void transition_out() = 0;
	virtual void update(sf::Event& event, int index) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};

