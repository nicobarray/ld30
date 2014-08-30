#include "Game.h"

Game::Game(void)
	: levels()
	, player(new Player(Ressource::getInstance().texture_get(TextureName::HERO), 0, 0))
	, current(LevelName::LVINTRO)
	, gui()
{
	levels.push_back(XMLParser::load_level("map/test.tmx", player));
}

Game::~Game(void)
{
}

void Game::transition_in(sf::RenderWindow& window)
{
	levels.at(current)->entities_add(player, true);
	levels.at(current)->player_get()->initGlove(10);
	levels.at(current)->entities_add(new Prop(Ressource::getInstance().texture_get((int)TextureName::PORTAL1), 5, 5, 32, 32, true, true), true);
	levels.at(current)->entities_add(new Prop(Ressource::getInstance().texture_get((int)TextureName::PORTAL1), 5, 5, 32, 32, true, true), false);
	gui.transition_in(player);
}

void Game::transition_out(sf::RenderWindow& window)
{
}

void Game::update(sf::Event& event, sf::RenderWindow& window, SceneName& index, std::vector<bool>& pressed_keys)
{
	std::cout << levels.at(current)->entities_get().size() << std::endl;
	if (!pressed_keys.at((int)sf::Keyboard::R) && sf::Keyboard::isKeyPressed(sf::Keyboard::R) || player->life_get() < 1)
	{
		transition_in(window);
		pressed_keys[(int)sf::Keyboard::R] = true;
	}
	else
	{
		// If END level, don't update
		if (current != LevelName::END)
		{
			// The world "follows" the player's dimension
			if (levels.at((int)current)->in_the_real_world_get() != player->real_get())
				levels.at((int)current)->in_the_real_world_set(player->real_get());

			// Update gui with player info
			gui.update(event, levels.at((int)current)->player_get());
		}
		else
		{
			index = SceneName::ENDSCREEN;
			return;
		}

		if (player->end_get())
		{
			if (current < END)
				current = (LevelName)((int)current + 1);
			player->end_set(false);
			if (current == END)
			{
				index = ENDSCREEN;
				current = (LevelName)0;
			}
			transition_in(window);
		}

		levels.at((int)current)->update();
	}
}

void Game::draw(sf::RenderWindow& window)
{
 	window.setView(player->view_get());

	// If END level, don't draw
	if (current != LevelName::END)
		levels.at((int)current)->draw(window);

	window.setView(window.getDefaultView());
	gui.draw(window);
}