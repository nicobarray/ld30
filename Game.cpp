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
		levels.at((int)LV1)->in_the_real_world_set(true);
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 3, 3);
		player->initGlove(4);
		levels.at((int)LV1)->clearEntity();
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 15, 2, 32, 32, true, 1));
		levels.at((int)LV1)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 15, 2, 32, 32, true, 1));
		levels.at((int)LV1)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 9, 3, 32, 32, true));
		levels.at((int)LV1)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)EXIT2), 3, 3, 32, 32, true, 2));
		levels.at((int)LV1)->addRealEntity(player);
		levels.at((int)LV1)->player_set(player);
		break;
	case LV2:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 3, 3);
		player->initGlove(6);
		levels.at((int)LV2)->clearEntity();
		levels.at((int)LV2)->addFairyEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV2), 10, 5));
		levels.at((int)LV2)->addRealEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV2), 15, 11));

		levels.at((int)LV2)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 15, 3, 32, 32, true, 1));
		levels.at((int)LV2)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 15, 3, 32, 32, true, 1));

		levels.at((int)LV2)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 12, 13, 32, 32, true, 1));
		levels.at((int)LV2)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 12, 13, 32, 32, true, 1));
		
		levels.at((int)LV2)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)EXIT2), 3, 13, 32, 32, true, 2));

		levels.at((int)LV2)->addRealEntity(player);
		levels.at((int)LV2)->player_set(player);
		levels.at((int)LV2)->in_the_real_world_set(false);
		player->real_set(false);
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
	if (player->end_get())
	{
		if (current < END)
			current = (LevelName)((int)current + 1);
		player->end_set(false);
		transition_in(window);
		if (current == END)
			index = MENU;
	}
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