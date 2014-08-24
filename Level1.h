#pragma once

#include "Level.h"

class Level1 : public Level
{
public:
	Level1(sf::Texture& real_world, sf::Texture& fairy_world);
	~Level1(void);
};
