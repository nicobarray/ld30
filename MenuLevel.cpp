#include "MenuLevel.h"

MenuLevel::MenuLevel(void)
	: background(Ressource::getInstance().texture_get((int)TITLE))
{
}

MenuLevel::~MenuLevel(void)
{

}

void MenuLevel::transition_in(sf::RenderWindow& window)
{

}

void MenuLevel::transition_out(sf::RenderWindow& window)
{

}

void MenuLevel::update(sf::Event& event, sf::RenderWindow& window, SceneName& index, std::vector<bool>& pressed_keys)
{
	if (!pressed_keys.at(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		index = GAME;
		pressed_keys[(int)sf::Keyboard::Space] = true;
	}
}

void MenuLevel::draw(sf::RenderWindow& window)
{
	window.draw(background);
}