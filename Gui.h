#pragma once

#include <SFML\Graphics.hpp>

#include "Ressource.h"
#include "Player.h"

class Gui
{
public:
	Gui(void);
	~Gui(void);

	void update(sf::Event& event, Player* player);
	void draw(sf::RenderWindow& window);

	void life_set(int i);
	void glove_set(int i);

private:
	sf::Sprite life_bar;
	sf::Sprite glove_bar;
	int life, max_life;
	int glove, max_glove;
};