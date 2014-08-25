#include "Gui.h"

Gui::Gui(void)
	: life_bar(Ressource::getInstance().texture_get((int)LIFE))
	, life_container(Ressource::getInstance().texture_get((int)LIFE_BACK))
	, glove_full(Ressource::getInstance().texture_get((int)GLOVE))
	, glove_empty(Ressource::getInstance().texture_get((int)GLOVE_BACK))
	, life(0)
	, max_life(6)
	, glove(3)
	, max_glove(3)
{
	int scale = 5;
	life_container.setPosition(16 - 9, 16 - 9);
	life_bar.setScale(scale, scale);
	life_container.setScale(scale, scale);
	glove_full.setScale(scale, scale);
	glove_empty.setScale(scale, scale);
}

Gui::~Gui(void)
{

}

void Gui::transition_in(Player* player)
{
	max_glove_set(player->max_glove_get());
}

void Gui::update(sf::Event& event, Player* player)
{
	life_set(player->life_get());
	glove_set(player->glove_get());
	std::cout << glove << std::endl;
}

void Gui::draw(sf::RenderWindow& window)
{
	window.draw(life_container);
	for (int i = 0; i < life; i++)
	{
		life_bar.setPosition(16 + i * (8*5), 16);
		window.draw(life_bar);
	}

	for (int i = 0; i < max_glove; i++)
	{
		int x = 16 + i * (8 * 5 + 4);
		int y = 16 + (8 * 5) + 16;

		if (i < glove)
		{
			glove_full.setPosition(x ,y);
			window.draw(glove_full);
		}
		else 
		{
			glove_empty.setPosition(x, y);
			window.draw(glove_empty);
		}
	}
}

void Gui::life_set(int i)
{
	life = i <= max_life ? i : max_life; 
}

void Gui::glove_set(int i)
{
	glove = i; 
}

void Gui::max_glove_set(int i)
{
	max_glove = i;
}