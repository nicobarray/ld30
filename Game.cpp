#include "Game.h"

Game::Game(void)
	: levels()
	, player(nullptr)
	, current(LVINTRO)
	, gui()
{
	player = new Player(Ressource::getInstance().texture_get((int)HERO), 16*4, 16*4);
	levels.push_back(new Level1(Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2)));
	levels.push_back(new Level2(Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2)));
	levels.push_back(new Level("map/level3.tmx", Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2)));
	//levels.push_back(new Level("map/level4.tmx", Ressource::getInstance().texture_get((int)TILESET1), Ressource::getInstance().texture_get((int)TILESET2)));
}

Game::~Game(void)
{
}

void Game::transition_in(sf::RenderWindow& window)
{
	switch (current)
	{
	case LVINTRO:
		levels.at(current)->in_the_real_world_set(true);
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 3, 3);
		player->initGlove(4);
		levels.at(current)->clearEntity();
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)MYSTERE), 29, 2, 32, 32, true, 1));
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 15, 2, 32, 32, true, 1));
		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 15, 2, 32, 32, true, 1));
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)CRATE), 9, 3, 32, 32, true));
		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)EXIT2), 3, 3, 32, 32, true, 2));
		levels.at(current)->addRealEntity(player);
		levels.at(current)->player_set(player);
		break;
	case LV2IMPS:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 3, 3);
		player->initGlove(5);

		levels.at(current)->clearEntity();
		levels.at(current)->addFairyEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at(current), 10, 5));
		levels.at(current)->addRealEntity(new Imp(Ressource::getInstance().texture_get((int)IMP), levels.at(current), 15, 11));
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
	case LV4PORTALS:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 2, 3);
		player->initGlove(5);
		levels.at(current)->clearEntity();
		
		levels.at(current)->addFairyEntity(new Spitter(Ressource::getInstance().texture_get((int)SPITTER), levels.at(current), 2, 10));

		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 2, 10, 32, 32, true, 1));
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 2, 10, 32, 32, true, 1));

		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 16, 10, 32, 32, true, 1));
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 16, 10, 32, 32, true, 1));

		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 16, 2, 32, 32, true, 1));
		levels.at(current)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 16, 2, 32, 32, true, 1));

		levels.at(current)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)EXIT2), 2, 2, 32, 32, true, 2));

		levels.at(current)->addRealEntity(player);
		levels.at(current)->player_set(player);
		levels.at(current)->in_the_real_world_set(true);
		player->real_set(true);
		break;
	/*case LV4:
		player = new Player(Ressource::getInstance().texture_get((int)HERO), 3, 4);
		player->initGlove(5);
		levels.at((int)LV4)->clearEntity();

		levels.at((int)LV4)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 3, 14, 32, 32, true, 1));
		levels.at((int)LV4)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 3, 14, 32, 32, true, 1));

		levels.at((int)LV4)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 3, 24, 32, 32, true, 1));
		levels.at((int)LV4)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 3, 24, 32, 32, true, 1));

		levels.at((int)LV4)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 14, 4, 32, 32, true, 1));
		levels.at((int)LV4)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 14, 4, 32, 32, true, 1));

		levels.at((int)LV4)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 14, 24, 32, 32, true, 1));
		levels.at((int)LV4)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 14, 24, 32, 32, true, 1));
		
		levels.at((int)LV4)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 25, 4, 32, 32, true, 1));
		levels.at((int)LV4)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 25, 4, 32, 32, true, 1));
		
		levels.at((int)LV4)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 25, 14, 32, 32, true, 1));
		levels.at((int)LV4)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 25, 14, 32, 32, true, 1));

		levels.at((int)LV4)->addFairyEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL2), 25, 24, 32, 32, true, 1));
		levels.at((int)LV4)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)PORTAL1), 25, 24, 32, 32, true, 1));

		levels.at((int)LV4)->addRealEntity(new Prop(Ressource::getInstance().texture_get((int)EXIT2), 14, 14, 32, 32, true, 2));

		levels.at((int)LV4)->addRealEntity(player);
		levels.at((int)LV4)->player_set(player);
		levels.at((int)LV4)->in_the_real_world_set(true);
		player->real_set(true);
		break;*/
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) || player->life_get() < 1)
		transition_in(window);
	else
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
				current = LVINTRO;
			}
			transition_in(window);
		}
		levels.at((int)current)->update();
	}

}

void Game::draw(sf::RenderWindow& window)
{
	window.setView(player->view_get());
	levels.at((int)current)->draw(window);

	window.setView(window.getDefaultView());
	gui.draw(window);
}