#pragma once

#include "rapidxml.hpp"

#include <set>

#include "Level.h"
#include "AllEntities.h"

class XMLParser
{
public:

	XMLParser(void);
	~XMLParser(void);

	static Level* load_level(std::string path, Player* player);
};

