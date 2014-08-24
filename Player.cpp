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
	if (anim != ATTACK)
	{
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			std::cout << "Attack !!\n";
			// attack...
			anim = ATTACK;
			frame_delay = 7;
			frame_id = 0;
			move_x = 0;
			move_y = 0;
		}
	}
}

void Player::die(int n)
{
	life-= n;
}

void Player::update(std::vector<Entity*> ground, std::vector<Entity*> items)
{
	Entity::update(ground, items);
	if (move_y != 0 || move_x != 0)
	{
		for (Entity* prop : items)
		{
			if (!prop->dead_get() && dynamic_cast<Prop*>(prop) && box.intersects(prop->box_get()))
			{
				std::cout << "It's a prop!\n";
				life+=dynamic_cast<Prop*>(prop)->lifeGain_get();
				prop->die(0);
			}
		}
	}
}
