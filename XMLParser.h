#pragma once

#include "rapidxml.hpp"

#include "Level.h"

class XMLParser
{
public:

	XMLParser(void);
	~XMLParser(void);

	static Level* load_level(std::string path);
};

