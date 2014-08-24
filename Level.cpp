#include "Level.h"

Level::Level(std::string file_name, sf::Texture& real_world, sf::Texture& fairy_world)
	: real_ground()
	, fairy_ground()
	, real_items()
	, fairy_items()
	, real_world(real_world)
	, fairy_world(fairy_world)
	, width(0)
	, height(0)
{
	// Read the xml file @ fileName and create the level from it

	using boost::property_tree::ptree;
	ptree pt;

	try
	{
		std::cout << "Parsing : " << file_name;
		read_xml(file_name, pt);
		std::cout << pt.get<std::string>("map.layer.<xmlattr>.name") << std::endl;

	}
	catch (...)
	{
		std::cout << "Error will parsing : " << file_name;
	}

	width = pt.get<int>("map.<xmlattr>.width");
	height = pt.get<int>("map.<xmlattr>.height");

	std::vector<int> tiles;
	std::vector<int> solids;

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("map.layer.data"))
	{
		tiles.push_back(v.second.get<int>("<xmlattr>.gid"));
	}
	
	BOOST_FOREACH(ptree::value_type &v, pt.get_child("map.solid.data"))
	{
		solids.push_back(v.second.get<int>("<xmlattr>.gid"));
	}

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			Entity* ent = new Entity(real_world, i * 16, j * 16, 16, 16, false);
			int index = i + j * width;

			int subindex = tiles.at(index);
			ent->sprite_get().setTextureRect(sf::IntRect(((subindex - 1) % 9) * 16, ((subindex - 1) / 9) * 16, 16, 16));
			ent->solid_set(solids.at(index));
			
			real_ground.push_back(ent);
		}
	}
}

Level::~Level(void)
{
	for(Entity* var : real_items)
		delete var;
}

std::vector<Entity*>& Level::ground_get()
{
	return real_ground;
}

std::vector<Entity*>& Level::items_get()
{
	return real_items;
}

void Level::update()
{
	for(Entity* var : real_items)
		var->update();
	for(Entity* var : real_items)
		var->update(real_ground, real_items);
}

void Level::draw(sf::RenderWindow& window)
{
	for(Entity* var : real_ground)
		var->draw(window);
	for(Entity* var : real_items)
		var->draw(window);
}

void Level::addEntity(Entity* e)
{
	real_items.push_back(e);
}

void Level::clearEntity()
{
	real_items.clear();
}