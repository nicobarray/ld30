#include "Game.h"

Game::Game(void)
	: levels()
	, player(nullptr)
	, current(LV1)
{
	player = new Player(Ressource::getInstance().texture_get((int)HERO), 16*4, 16*4);
	levels.push_back(new Level1(Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2)));
	levels.push_back(new Level2(Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2)));
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
		levels.at((int)LV1)->addRealEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV1), 16*10, 16*7));
		levels.at((int)LV1)->addRealEntity(new Spitter(Ressource::getInstance().texture_get((int)SPITTER), levels.at((int)LV1), 16*9, 16*9));
		levels.at((int)LV1)->addRealEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16 * 5, 16 * 6));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 16 * 4, 16 * 12, 32, 32, true));
		levels.at((int)LV1)->addRealEntity(player);
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)TILESET2), 16 * 2, 16 * 2, 16, 16, true)); 
		break;
	case LV2:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 16*4, 16*4);
		levels.at((int)LV2)->clearEntity();
		levels.at((int)LV2)->addRealEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV2), 16*10, 16*5));
		levels.at((int)LV2)->addRealEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
		levels.at((int)LV2)->addRealEntity(player);
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