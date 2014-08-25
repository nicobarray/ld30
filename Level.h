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
	Level(std::string fileName, sf::Texture& real_world, sf::Texture& fairy_world);
	~Level(void);

	std::vector<Entity*>& ground_real_get();
	std::vector<Entity*>& ground_fairy_get();
	std::vector<Entity*>& items_get();

	virtual void update();
	virtual void draw(sf::RenderWindow& window);

	void addRealEntity(Entity* e);
	void addFairyEntity(Entity* e);
	void addEntity(Entity* e);
	void clearEntity();

	void in_the_real_world_set(bool b);
	bool in_the_real_world_get();
	
	Player* player_get();
	void player_set(Player* p);

private:
	std::vector<Entity*> real_ground, fairy_ground;
	std::vector<Entity*> items;
	sf::Texture& real_world;
	sf::Texture& fairy_world;
	int width;
	int height;
	bool in_the_real_world;
	Player* player;
};

