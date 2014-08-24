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

void Player::update()
{
	Entity::update();

	int speed = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		// move left...
			move_x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		// move right...
		move_x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		// up...
		move_y -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		// down...
		move_y += speed;
}