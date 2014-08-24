#include "MenuMain.h"


MenuMain::MenuMain(void)
	: background(Ressource::getInstance().texture_get((int)TITLE))
{
}


MenuMain::~MenuMain(void)
{
}

void MenuMain::transition_in(sf::RenderWindow& window)
{

}

void MenuMain::transition_out(sf::RenderWindow& window)
{

}

void MenuMain::update(sf::Event& event, sf::RenderWindow& window, SceneName& index)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		index = LVL;
}

void MenuMain::draw(sf::RenderWindow& window)
{
	window.draw(background);
}