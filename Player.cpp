#include "Player.h"


Player::Player(SDL_Surface *t, int x, int y, int w, int h)
	: Entity(t, x, y, w, h, false)
	, life(12)
	, item(nullptr)
{
}


Player::~Player(void)
{
}
