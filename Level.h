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
	Level(std::string fileName, sf::Texture& tileset);
	~Level(void);

	std::vector<Entity*>& ground_get();
	std::vector<Entity*>& items_get();

	void update();
	void draw(sf::RenderWindow& window);

	void addEntity(Entity* e);

private:
	std::vector<Entity*> ground;
	std::vector<Entity*> items;
	sf::Texture& tileset;
	int width;
	int height;
};

