#include "MenuMain.h"

MenuMain::MenuMain(void)
	: background(Ressource::getInstance().texture_get((int)TITLE))
{
	background.scale(2, 2);
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

void MenuMain::update(sf::Event& event, sf::RenderWindow& window, SceneName& index, std::vector<bool>& pressed_keys)
{
	if (!pressed_keys[sf::Keyboard::Space] && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		index = LVL;
		pressed_keys[sf::Keyboard::Space] = true;
	}
}

void MenuMain::draw(sf::RenderWindow& window)
{
	window.draw(background);
}