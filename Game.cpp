#include "Game.h"

Game::Game(void)
	: levels()
	, player(nullptr)
	, current(LV1)
	, gui()
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
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 3, 3);
		levels.at((int)LV1)->clearEntity();
		/*levels.at((int)LV1)->addRealEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV1), 16*10, 16*7));
		levels.at((int)LV1)->addRealEntity(new Spitter(Ressource::getInstance().texture_get((int)SPITTER), levels.at((int)LV1), 16*9, 16*9));
		levels.at((int)LV1)->addRealEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16 * 5, 16 * 6));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 16 * 4, 16 * 13, 32, 32, true));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 16 * 4, 16 * 14, 32, 32, true));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 16 * 4, 16 * 15, 32, 32, true));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 16 * 4, 16 * 16, 32, 32, true));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 16 * 4, 16 * 17, 32, 32, true));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL), 16 * 2, 16 * 2, 32, 32, true, true));
		levels.at((int)LV1)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL), 16 * 2, 16 * 2, 32, 32, true, true)); 
		levels.at((int)LV1)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)DOOR), 16 * 2, 16 * 12, 32, 32, false));*/
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 15, 2, 32, 32, true, true));
		levels.at((int)LV1)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 15, 2, 32, 32, true, true));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 9, 3, 32, 32, true));
		levels.at((int)LV1)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)DOOR), 3, 3, 32, 32, false, true));
		levels.at((int)LV1)->addRealEntity(new Spitter(Ressource::getInstance().texture_get((int)SPITTER), levels.at((int)LV1), 9, 9));
		levels.at((int)LV1)->addRealEntity(player);
		levels.at((int)LV1)->player_set(player);
		break;
	case LV2:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 16*4, 16*4);
		levels.at((int)LV2)->clearEntity();
		levels.at((int)LV2)->addRealEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV2), 16*10, 16*5));
		levels.at((int)LV2)->addRealEntity(newPotion(Ressource::getInstance().texture_get((int)DROPHEALTH), 16*5, 16*6));
		levels.at((int)LV2)->addRealEntity(player);
		levels.at((int)LV2)->player_set(player);
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
	levels.at((int)current)->in_the_real_world_set(player->real_get());
	levels.at((int)current)->update();
	gui.update(event, levels.at((int)current)->player_get());
}

void Game::draw(sf::RenderWindow& window)
{
	window.setView(player->view_get());
	levels.at((int)current)->draw(window);
	
	window.setView(window.getDefaultView());
	gui.draw(window);
}