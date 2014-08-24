#pragma once

#include <SFML\Graphics.hpp>

#include "Scene.h"

class MenuLevel : public Scene
{
public:
	MenuLevel(void);
	virtual ~MenuLevel(void) override;
	virtual void transition_in(sf::RenderWindow& window) override;
	virtual void transition_out(sf::RenderWindow& window) override;
	virtual void update(sf::Event& event, sf::RenderWindow& window, int index) override;
	virtual void draw(sf::RenderWindow& window) override;
};