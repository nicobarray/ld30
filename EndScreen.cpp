#include "EndScreen.h"


EndScreen::EndScreen(void)
	: background(Ressource::getInstance().texture_get((int)GAMEOVER))
{
	background.scale(2, 2);
}

EndScreen::~EndScreen(void)
{
}

void EndScreen::transition_in(sf::RenderWindow& window)
{

}

void EndScreen::transition_out(sf::RenderWindow& window)
{

}

void EndScreen::update(sf::Event& event, sf::RenderWindow& window, SceneName& index)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		index = GAME;
}

void EndScreen::draw(sf::RenderWindow& window)
{
	window.draw(background);
}