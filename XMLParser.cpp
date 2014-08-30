#include "XMLParser.h"

XMLParser::XMLParser(void)
{
}

XMLParser::~XMLParser(void)
{
}

Level* XMLParser::load_level(std::string path)
{
	Level* level = new Level();
	std::ifstream file(path);
	std::stringstream buffer;

	buffer << file.rdbuf();
	file.close();

	std::string xml(buffer.str());
	rapidxml::xml_document<> tmx;

	tmx.parse<0>(&xml[0]);

	rapidxml::xml_node<> *map = tmx.first_node();

	level->map_width_set(atoi(map->first_attribute("width")->value()));
	level->map_height_set(atoi(map->first_attribute("height")->value()));

	sf::Texture& texture_real = Ressource::getInstance().getInstance().texture_get(TextureName::TILESET1);
	sf::Texture& texture_fairy = Ressource::getInstance().getInstance().texture_get(TextureName::TILESET2);
	int index = 0;
	Entity* tile_entity = nullptr;

	std::vector<int> solids;

	for (rapidxml::xml_node<> *node = map->first_node("tileset"); node; node = node->next_sibling())
	{
		for (rapidxml::xml_node<> *tile = node->first_node("tile"); tile; tile = tile->next_sibling())
		{
			solids.push_back(atoi(tile->first_attribute("id")->value()));
		}
	}

	for (rapidxml::xml_node<> *node = map->first_node("layer"); node; node = node->next_sibling())
	{
		std::string layer_name = node->first_attribute("name")->value();

		if (layer_name == "real")
		{
			index = 0;
			for (rapidxml::xml_node<> *tile = node->first_node("data")->first_node("tile"); tile; tile = tile->next_sibling())
			{
				int x = index % level->map_width_get();
				int y = index / level->map_width_get();

				tile_entity = new Prop(texture_real, x, y, 16, 16, false);

				int gid = atoi(tile->first_attribute("gid")->value());

				int subx = ((gid - 1) % 9) * 16;
				int suby = ((gid - 1) / 9) * 16;

				// Set the correct subx and suby
				tile_entity->sprite_get().setTextureRect(sf::IntRect(subx, suby, 16, 16));

				for (int solid : solids)
				{
					if (gid == solid)
					{
						tile_entity->solid_set(true);
						break;
					}
				}

				level->tiles_real_add(tile_entity);
				index++;
			}
		} else if (layer_name == "fairy")
		{
			index = 0;
			for (rapidxml::xml_node<> *tile = node->first_node("data")->first_node("tile"); tile; tile = tile->next_sibling())
			{
				int x = index % level->map_width_get();
				int y = index / level->map_width_get();

				tile_entity = new Prop(texture_fairy, x, y, 16, 16, false);

				int gid = atoi(tile->first_attribute("gid")->value()) - 108;

				int subx = ((gid - 1) % 9) * 16;
				int suby = ((gid - 1) / 9) * 16;

				// Set the correct subx and suby
				tile_entity->sprite_get().setTextureRect(sf::IntRect(subx, suby, 16, 16));
				
				for (int solid : solids)
				{
					if (gid == solid)
					{
						tile_entity->solid_set(true);
						break;
					}
				}

				level->tiles_fairy_add(tile_entity);
				index++;
			}
		}
	}

	return level;
}