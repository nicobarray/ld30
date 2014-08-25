#pragma once

#include <SFML\Graphics.hpp>

#include "Ressource.h"

class Gui
{
public:
	Gui(void);
	~Gui(void);

	void update(sf::Event& event);
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite life_bar;
	int life, max_life;
};