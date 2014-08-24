#include "Player.h"
#include "Imp.h"

Player::Player(sf::Texture& t, int x, int y)
	: Entity(t, x, y, 32, 32, true)
	, life(12)
	, item(nullptr)
	, view(sf::FloatRect(0, 0, 16 *3 * 16, 16 * 3 * 16))
{
}

Player::~Player(void)
{
}

void Player::update()
{
	dead = false;
	if (invu)
		invu--;
	Entity::update();

	int speed = 3;
	if (anim != ATTACK && anim != DEATH)
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

	view.setCenter(location.left + location.width / 2, location.top + location.height / 2);
	std::cout << view.getCenter().x << std::endl;

	for (Entity* prop : items)
	{
		if (!prop->dead_get() && prop->anim_get() == ATTACK && !invu && dynamic_cast<Imp*>(prop))
		{
			int x = box.left + box.width/2;
			int y = box.top + box.height/2;
			int x2 = x;
			int y2 = y;

			x2 = prop->box_get().left + prop->box_get().width/2;
			y2 = prop->box_get().top + prop->box_get().height/2;

			move_x = x2 - x;
			move_y = y2 - y;
			int speed = 2;
			int dist = move_x * move_x + move_y * move_y;
			dist  = sqrt(dist);
			if (dist < 70)
			{
				std::cout << "It's an imp! (" << life << ")\n";
				life--;
				anim = DEATH;
				frame_id = 0;
				frame_delay = 7;
				invu = 120;
				move_x = -(3.5f * move_x)/dist;
				move_y = -(3.5f * move_y)/dist;
			}
		}
	}
}

sf::View& Player::view_get()
{
	return view;
}
