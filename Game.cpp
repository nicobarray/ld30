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
	levels.push_back(new Level("map/level3.tmx", Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2)));
}

Game::~Game(void)
{
}

void Game::transition_in(sf::RenderWindow& window)
{
	switch (current)
	{
	case LV1:
		levels.at(current)->in_the_real_world_set(true);
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 3, 3);
		player->initGlove(4);
		levels.at(current)->clearEntity();
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 15, 2, 32, 32, true, 1));
		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 15, 2, 32, 32, true, 1));
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 9, 3, 32, 32, true));
		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)EXIT2), 3, 3, 32, 32, true, 2));
		levels.at(current)->addRealEntity(player);
		levels.at(current)->player_set(player);
		break;
	case LV2:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 3, 3);
		player->initGlove(5);

		levels.at(current)->clearEntity();
		levels.at(current)->addFairyEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV2), 10, 5));
		levels.at(current)->addRealEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at((int)LV2), 15, 11));
		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 15, 3, 32, 32, true, 1));
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 15, 3, 32, 32, true, 1));
		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 12, 13, 32, 32, true, 1));
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 12, 13, 32, 32, true, 1));
		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)EXIT2), 3, 13, 32, 32, true, 2));
		levels.at(current)->addRealEntity(player);
		levels.at(current)->player_set(player);
		levels.at(current)->in_the_real_world_set(false);
		player->real_set(false);
		break;
	case LV3:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 2, 3);
		player->initGlove(4);
		levels.at((int)LV3)->clearEntity();

		levels.at((int)LV3)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 2, 10, 32, 32, true, 1));
		levels.at((int)LV3)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 2, 10, 32, 32, true, 1));
		
		levels.at((int)LV3)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 16, 10, 32, 32, true, 1));
		levels.at((int)LV3)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 16, 10, 32, 32, true, 1));

		levels.at((int)LV3)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 16, 2, 32, 32, true, 1));
		levels.at((int)LV3)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 16, 2, 32, 32, true, 1));

		levels.at((int)LV3)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)EXIT2), 2, 2, 32, 32, true, 2));

		levels.at((int)LV3)->addRealEntity(player);
		levels.at((int)LV3)->player_set(player);
		levels.at((int)LV3)->in_the_real_world_set(true);
		player->real_set(true);
		break;
	default:
		break;
	}

	gui.transition_in(player);
}

void Game::transition_out(sf::RenderWindow& window)
{
}

void Game::update(sf::Event& event, sf::RenderWindow& window, SceneName& index)
{
	levels.at((int)current)->in_the_real_world_set(player->real_get());
	gui.update(event, levels.at((int)current)->player_get());
	if (player->end_get())
	{
		if (current < END)
			current = (LevelName)((int)current + 1);
		player->end_set(false);
		if (current == END)
		{
			index = ENDSCREEN;
			current = LV1;
		}
		transition_in(window);
	}
	levels.at((int)current)->update();

}

void Game::draw(sf::RenderWindow& window)
{
	window.setView(player->view_get());
	levels.at((int)current)->draw(window);

	window.setView(window.getDefaultView());
	gui.draw(window);
}