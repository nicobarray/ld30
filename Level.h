#pragma once

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <fstream>

#include <SFML\Graphics.hpp>

#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\xml_parser.hpp>
#include <boost\foreach.hpp>

#include "Entity.h"

class Level
{
public:
	Level(std::string fileName, sf::Texture& real_world, sf::Texture& fairy_world);
	~Level(void);

	std::vector<Entity*>& ground_get();
	std::vector<Entity*>& items_get();

	virtual void update();
	virtual void draw(sf::RenderWindow& window);

	void addEntity(Entity* e);
	void clearEntity();

private:
	std::vector<Entity*> real_ground, fairy_ground;
	std::vector<Entity*> real_items, fairy_items;
	sf::Texture& real_world;
	sf::Texture& fairy_world;
	int width;
	int height;
};

