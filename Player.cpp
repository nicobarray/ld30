#include "Player.h"


Player::Player(sf::Texture& t, int x, int y)
	: Entity(t, x, y, 32, 32, false)
	, life(12)
	, item(nullptr)
{
}


Player::~Player(void)
{
}
