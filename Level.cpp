#include "Level.h"
#include "XMLParser.h"

Level::Level()
	: tiles_real()
	, tiles_fairy()
	, entities()
	, texture_real(Ressource::getInstance().texture_get((int)TextureName::TILESET1))
	, texture_fairy(Ressource::getInstance().texture_get((int)TextureName::TILESET2))
	, map_width(0)
	, map_height(0)
	, in_the_real_world(true)
	, player(nullptr)
{
}

Level::Level(std::string file_name, const sf::Texture& real_world, const sf::Texture& fairy_world)
	: tiles_real()
	, tiles_fairy()
	, entities()
	, texture_real(real_world)
	, texture_fairy(fairy_world)
	, map_width(0)
	, map_height(0)
	, in_the_real_world(true)
	, player(nullptr)
{
	// Read the xml file @ fileName and create the level from it
	// XMLParser::load_level(file_name);

}

Level::Level(const Level& level)
	: tiles_real(level.tiles_real)
	, tiles_fairy(level.tiles_fairy)
	, entities(level.entities)
	, texture_real(level.texture_real)
	, texture_fairy(level.texture_fairy)
	, map_width(level.map_width)
	, map_height(level.map_height)
	, in_the_real_world(level.in_the_real_world)
	, player(level.player)
{
}

Level::~Level(void)
{
	entities.clear();
	tiles_real.clear();
	tiles_fairy.clear();
}

void Level::update()
{
	for(Entity* var : entities)
	{
		if (var->real_get() == in_the_real_world)
		{
			int dx = var->location_get().left - player->location_get().left;
			int dy = var->location_get().top - player->location_get().top;

			if ((dx < 300 || dx > -300) && (dy < 300 || dy > -300))
				var->update();
		}
	}

	for(Entity* var : entities)
	{
		if (var->real_get() == in_the_real_world)
			var->update(in_the_real_world ? tiles_real : tiles_fairy, entities);
	}
}

void Level::draw(sf::RenderWindow& window)
{
	for(Entity* var : in_the_real_world ? tiles_real : tiles_fairy)
		var->draw(window);

	std::sort(entities.begin(), entities.end(), compare);

	for(Entity* var : entities)
	{
		if (var->real_get() == in_the_real_world)
			var->draw(window);
	}
}

// GETTERS & SETTERS

// In_the_real_world boolean

void Level::in_the_real_world_set(bool b)
{
	in_the_real_world = b;
	SoundPlayer::getInstance().stop_music(in_the_real_world);
	SoundPlayer::getInstance().play_music(!in_the_real_world);
}

bool Level::in_the_real_world_get()
{
	return in_the_real_world;
}

// Tiles

std::vector<Entity*>& Level::tiles_real_get()
{
	return tiles_real;
}

void Level::tiles_real_add(Entity* e)
{
	tiles_real.push_back(e);
}

std::vector<Entity*>& Level::tiles_fairy_get()
{
	return tiles_fairy;
}

void Level::tiles_fairy_add(Entity* e)
{
	tiles_fairy.push_back(e);
}

std::vector<Entity*>& Level::tiles_current_get()
{
	return in_the_real_world ? tiles_real_get() : tiles_fairy_get();
}

// Entities

std::vector<Entity*>& Level::entities_get()
{
	return entities;
}

void Level::entities_add(Entity* e, bool real)
{
	e->real_set(real);
	entities.push_back(e);
}

// Player

Player* Level::player_get()
{
	return player;
}

void Level::player_set(Player* p)
{
	player = p;
}

// Map size

void Level::map_width_set(int i)
{
	map_width = i;
}

void Level::map_height_set(int i)
{
	map_height = i;
}

int Level::map_width_get()
{
	return map_width;
}

int Level::map_height_get()
{
	return map_height;
}
