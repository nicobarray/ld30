#include "Gui.h"

Gui::Gui(void)
	: life_bar(Ressource::getInstance().texture_get((int)LIFE))
	, glove_bar(Ressource::getInstance().texture_get((int)LIFE))
	, life(3)
	, max_life(3)
	, glove(3)
	, max_glove(3)
{
	life_bar.setScale(6, 6);
	glove_bar.setScale(6, 6);

	glove_bar.setColor(sf::Color(0, 75, 255));
}

Gui::~Gui(void)
{
}

void Gui::update(sf::Event& event, Player* player)
{
	life_set(player->life_get());
	glove_set(player->glove_get());
}

void Gui::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < life; i++)
	{
		life_bar.setPosition(16 + i * 32, 16);
		window.draw(life_bar);
	}
	
	for (int i = 0; i < glove; i++)
	{
		glove_bar.setPosition(16 + i * 32, 16 + 64);
		window.draw(glove_bar);
	}
}

void Gui::life_set(int i)
{
	life = i <= max_life ? i : max_life; 
}

void Gui::glove_set(int i)
{
	glove = i <= max_glove ? i : max_glove; 
}