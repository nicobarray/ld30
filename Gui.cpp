#include "Gui.h"

Gui::Gui(void)
	: life_bar(Ressource::getInstance().texture_get((int)LIFE))
	, life(3)
	, max_life(3)
{
	life_bar.setScale(6, 6);
}

Gui::~Gui(void)
{
}

void Gui::update(sf::Event& event)
{

}

void Gui::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < life; i++)
	{
		
		life_bar.setPosition(16 + i * 36, 16);
		window.draw(life_bar);
	}
}