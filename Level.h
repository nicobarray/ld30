#pragma once

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <SFML\Graphics.hpp>

#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\xml_parser.hpp>
#include <boost\foreach.hpp>

#include "Prop.h"
#include "Ressource.h"
#include "Player.h"

class Level
{
public:
	Level();
	Level(std::string path, const sf::Texture& real_world, const sf::Texture& fairy_world);
	~Level(void);
	
	virtual void update();
	virtual void draw(sf::RenderWindow& window);

	std::vector<Entity*>& tiles_real_get();
	void tiles_real_add(Entity* tile);
	std::vector<Entity*>& tiles_fairy_get();
	void tiles_fairy_add(Entity* tile);
	
	std::vector<Entity*>& tiles_current_get();

	// Get the vector containing all entities (player, mobs, dynamic objs, etc.)
	std::vector<Entity*>& entities_get();
	void entities_real_add(Entity* e);
	void entities_fairy_add(Entity* e);
	
	void in_the_real_world_set(bool b);
	bool in_the_real_world_get();
	
	Player* player_get();
	void player_set(Player* p);

	void map_width_set(int i);
	void map_height_set(int i);
	
	int map_width_get();
	int map_height_get();

private:
	std::vector<Entity*> tiles_real, tiles_fairy;
	std::vector<Entity*> entities;

	const sf::Texture& texture_real;
	const sf::Texture& texture_fairy;

	int map_width;
	int map_height;

	bool in_the_real_world;

	Player* player;
};

