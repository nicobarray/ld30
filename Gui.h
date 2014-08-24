#pragma once

#include <SFML\Graphics.hpp>

class Gui
{
public:
	Gui(void);
	~Gui(void);

	void update(sf::Event& event);
	void draw(sf::RenderWindow& window);
};

