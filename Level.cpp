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
	, player(nullptr)
{
	// Read the xml file @ fileName and create the level from it

#pragma region XML loader

	using boost::property_tree::ptree;
	ptree pt;

	try
	{
		read_xml(file_name, pt);
	}
	catch (...)
	{
		std::cout << "Error while parsing : " << file_name;
	}

	width = pt.get<int>("map.<xmlattr>.width");
	height = pt.get<int>("map.<xmlattr>.height");

	std::vector<int> real_tiles;
	std::vector<int> real_solids;
	std::vector<int> fairy_tiles;
	std::vector<int> fairy_solids;

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("map.realground.data"))
	{
		real_tiles.push_back(v.second.get<int>("<xmlattr>.gid"));
	}
	
	BOOST_FOREACH(ptree::value_type &v, pt.get_child("map.realsolid.data"))
	{
		real_solids.push_back(v.second.get<int>("<xmlattr>.gid"));
	}
	
	BOOST_FOREACH(ptree::value_type &v, pt.get_child("map.fairyground.data"))
	{
		fairy_tiles.push_back(v.second.get<int>("<xmlattr>.gid") - 108);
	}
	
	BOOST_FOREACH(ptree::value_type &v, pt.get_child("map.fairysolid.data"))
	{
		fairy_solids.push_back(v.second.get<int>("<xmlattr>.gid"));
	}
	

#pragma endregion
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			Entity* real_tile = new Prop(real_world, i, j, 16, 16, false);
			Entity* fairy_tile = new Prop(fairy_world, i, j, 16, 16, false);
			int index = i + j * width;

			int real_sub_index = real_tiles.at(index);
			int fairy_sub_index = fairy_tiles.at(index);

			real_tile->sprite_get().setTextureRect(sf::IntRect(((real_sub_index - 1) % 9) * 16, ((real_sub_index - 1) / 9) * 16, 16, 16));
			real_tile->solid_set(real_solids.at(index));

			fairy_tile->sprite_get().setTextureRect(sf::IntRect(((fairy_sub_index - 1) % 9) * 16, ((fairy_sub_index - 1) / 9) * 16, 16, 16));
			fairy_tile->solid_set(fairy_solids.at(index));

			real_ground.push_back(real_tile);
			fairy_ground.push_back(fairy_tile);
		}
	}

	std::cout << "Done with : " << file_name << "\n";
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
	SoundPlayer::getInstance().stop_music(in_the_real_world);
	SoundPlayer::getInstance().play_music(!in_the_real_world);
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
std::vector<Entity*>& Level::ground_get()
{
	return in_the_real_world ? real_ground : fairy_ground;
}

std::vector<Entity*>& Level::items_get()
{
	return items;
}

Player* Level::player_get()
{
	return player;
}

void Level::player_set(Player* p)
{
	player = p;
}