#include "Gui.h"

Gui::Gui(void)
	: life_bar(Ressource::getInstance().texture_get((int)LIFE))
	, life_container(Ressource::getInstance().texture_get((int)LIFE_BACK))
	, glove_full(Ressource::getInstance().texture_get((int)GLOVE))
	, glove_empty(Ressource::getInstance().texture_get((int)GLOVE_BACK))
	, life(3)
	, max_life(3)
	, glove(3)
	, max_glove(3)
{
	life_container.setPosition(16 - 2, 16 - 2);
	life_bar.setScale(6, 6);
	life_container.setScale(6, 6);
	glove_full.setScale(6, 6);
	glove_empty.setScale(6, 6);
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
	window.draw(life_container);
	for (int i = 0; i < life; i++)
	{
		life_bar.setPosition(16 + i * 64, 16);
		window.draw(life_bar);
	}

	for (int i = 0; i < glove; i++)
	{
	/*	glove.setPosition(16 + i * 32, 16 + 64);
		window.draw(glove_bar);*/
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