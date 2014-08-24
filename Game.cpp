#include "Game.h"

Game::Game(void)
	: levels()
	, player(nullptr)
	, current(LV1)
{
	player = new Player(Ressource::getInstance().texture_get((int)HERO), 16 * 4, 16 * 4);
	Level1* level1 = new Level1(Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2));
	Level2* level2 = new Level2(Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2));

	level1->addEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), level1, 16*10, 16*5));
	level1->addEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
	level1->addEntity(player);

	level2->addEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), level2, 16*10, 16*5));
	level2->addEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
	level2->addEntity(player);

	levels.push_back(level1);
	levels.push_back(level2);
}

Game::~Game(void)
{
}

void Game::transition_in(sf::RenderWindow& window)
{
	switch (current)
	{
	case LV1:	
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 16*4, 16*4);
		levels.at((int)LV1)->clearEntity();
		levels.at((int)LV1)->addEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV1), 16*10, 16*5));
		levels.at((int)LV1)->addEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
		levels.at((int)LV1)->addEntity(player);
		break;
	case LV2:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 16*4, 16*4);
		levels.at((int)LV2)->clearEntity();
		levels.at((int)LV2)->addEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV2), 16*10, 16*5));
		levels.at((int)LV2)->addEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
		levels.at((int)LV2)->addEntity(player);
		break;
	default:
		break;
	}
}

void Game::transition_out(sf::RenderWindow& window)
{

}

void Game::update(sf::Event& event, sf::RenderWindow& window, SceneName& index)
{
	levels.at((int)current)->update();

}

void Game::draw(sf::RenderWindow& window)
{
	window.setView(player->view_get());
	levels.at((int)current)->draw(window);
}