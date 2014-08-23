#include "Level.h"

Level::Level(std::string fileName)
	: ground(), items()
{
	std::string line = "";
	std::string text = "";
	std::ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> line;
			text += line + ' ';
		}
	}
	else std::cerr << "Unable to open file"; 

	myfile.close();

	std::cout << text << '\n';

	rapidxml::xml_document<> doc;							// character type defaults to char

	doc.parse<0>(const_cast<char*>(text.c_str()));			// 0 means default parse flags

	std::cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
	rapidxml::xml_node<> *node = doc.first_node("data");
	std::cout << "Node foobar has value " << node->value() << "\n";
	for (rapidxml::xml_attribute<> *attr = node->first_attribute();
		attr; attr = attr->next_attribute())
	{
		std::cout << "Node foobar has attribute " << attr->name() << " ";
		std::cout << "with value " << attr->value() << "\n";
	}

	int w = 16;
	int h = 16;
	for (int i = 0; i < w; i++)
	{
		ground.push_back(std::vector<bool>());
		for (int j = 0; j < h; j++)
		{
			ground[i].push_back(true);
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
		var->update();
	for(Entity* var : items)
		var->update(items);
}

void Level::draw(SDL_Surface* screen)
{
	for(Entity* var : items)
		var->draw(screen);
}

void Level::addEntity(Entity* e)
{
	items.push_back(e);
}