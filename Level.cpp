#include "Level.h"

Level::Level(std::string file_name, sf::Texture& real_world, sf::Texture& fairy_world)
	: real_ground()
	, fairy_ground()
	, items()
	, real_world(real_world)
	, fairy_world(fairy_world)
	, width(0)
	, height(0)
	, in_the_real_world(true)
{
	// Read the xml file @ fileName and create the level from it

#pragma region XML loader

	using boost::property_tree::ptree;
	ptree pt;

	try
	{
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

#pragma endregion

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			Entity* real_tile = new Prop(real_world, i * 16, j * 16, 16, 16, false);
			Entity* fairy_tile = new Prop(fairy_world, i * 16, j * 16, 16, 16, false);
			int index = i + j * width;

			int subindex = tiles.at(index);
			real_tile->sprite_get().setTextureRect(sf::IntRect(((subindex - 1) % 9) * 16, ((subindex - 1) / 9) * 16, 16, 16));
			real_tile->solid_set(solids.at(index));
			fairy_tile->sprite_get().setTextureRect(sf::IntRect(((subindex - 1) % 9) * 16, ((subindex - 1) / 9) * 16, 16, 16));
			fairy_tile->solid_set(solids.at(index));

			real_ground.push_back(real_tile);
			fairy_ground.push_back(fairy_tile);
		}
	}
}

Level::~Level(void)
{
	for(Entity* var : items)
		delete var;
}

void Level::update()
{
	for(Entity* var : items)
	{
		if (var->real_get() == in_the_real_world)
			var->update();
	}
	for(Entity* var : items)
	{
			var->update(in_the_real_world ? real_ground : fairy_ground, items);
	}
}

void Level::draw(sf::RenderWindow& window)
{
	for(Entity* var : in_the_real_world ? real_ground : fairy_ground)
		var->draw(window);

	std::sort(items.begin(), items.end(), compare);

	for(Entity* var : items)
	{
		if (var->real_get() == in_the_real_world)
			var->draw(window);
	}
}

void Level::addRealEntity(Entity* e)
{
	items.push_back(e);
}

void Level::addFairyEntity(Entity* e)
{
	e->real_set(false);
	items.push_back(e);
}

void Level::clearEntity()
{
	items.clear();
}

void Level::in_the_real_world_set(bool b)
{
	in_the_real_world = b;
}

bool Level::in_the_real_world_get()
{
	return in_the_real_world;
}

std::vector<Entity*>& Level::ground_real_get()
{
	return real_ground;
}

std::vector<Entity*>& Level::ground_fairy_get()
{
	return fairy_ground;
}

std::vector<Entity*>& Level::items_get()
{
	return items;
}