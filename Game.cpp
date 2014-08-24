#include "Game.h"

Game::Game(void)
	: level1(Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2))
	, level2(Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2))
	, player(nullptr)
{
	player = new Player(Ressource::getInstance().texture_get((int)HERO), 16*4, 16*4);

	level1.clearEntity();
	level2.clearEntity();

	level1.addEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), &level1, 16*10, 16*7));
	level1.addEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
	level1.addEntity(player);

	level2.addEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), &level1, 16*10, 16*5));
	level2.addEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
	level2.addEntity(player);
}

Game::~Game(void)
{
}

void Game::transition_in(sf::RenderWindow& window)
{
	player = new Player(Ressource::getInstance().texture_get((int)HERO), 16*4, 16*4);

	level1.clearEntity();

	level1.addEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), &level1, 16*10, 16*7));
	level1.addEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
	level1.addEntity(player);
	
	level2.addEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), &level1, 16*10, 16*5));
	level2.addEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
	level2.addEntity(player);
}

void Game::transition_out(sf::RenderWindow& window)
{
	level1.clearEntity();
}

void Game::update(sf::Event& event, sf::RenderWindow& window, int index)
{
	level1.update();
}

void Game::draw(sf::RenderWindow& window)
{
	window.setView(player->view_get());
	level1.draw(window);
}