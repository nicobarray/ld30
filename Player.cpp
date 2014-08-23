#include "Player.h"


Player::Player(SDL_Surface *t, int x, int y)
	: Entity(t, x, y)
	, life(12)
	, item(nullptr)
{
}


Player::~Player(void)
{
}
