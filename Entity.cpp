#include "Entity.h"

#define SCALE = 3

int abs(int n)
{
	if (n > 0)
		return n;
	else
		return -n;
}

Entity::Entity(sf::Texture& texture, int x, int y, int w, int h, bool s)
	: location(x * 3, y * 3, w * 3, h * 3)
	, subrect(0, 0, w, h)
	, texture(texture)
	, sprite(texture, sf::IntRect(0, 0, w, h))
	, solid(s)
	, move_x(0)
	, move_y(0)
	, direction(0)
	, frame_id(0)
	, frame_delay(7)
	, anim(IDLE)
{
	location_set(x * 3, y * 3, w, h);
	sprite.setScale(3, 3);
}

Entity::~Entity(void)
{
}

void Entity::location_set(int x, int y, int w, int h)
{
	location.left = x;
	location.top = y;
	location.width = w;
	location.height = h;
	sprite.setPosition(x, y);
}
sf::IntRect& Entity::location_get()
{
	return location;
}
void Entity::texture_set(sf::Texture& tex)
{
	texture = tex;
}

void Entity::update()
{
	move_x = 0;
	move_y = 0;

}

void Entity::update(std::vector<Entity*> v)
{
	if (move_y != 0 || move_x != 0)
	{
		if (anim == IDLE)
			frame_id = 0;
		anim = RUN;
		if (move_y > 0 && move_y > abs(move_x))
			direction = SOUTH;
		else if (move_y < 0 && -move_y > abs(move_x))
			direction = NORTH;
		else if (move_x > 0 && move_x > abs(move_y))
			direction = EAST;
		else if (move_x < 0 && -move_x > abs(move_y))
			direction = WEST;
		move();
		updateSubrect();
	}
	else
		anim = IDLE;
	if (solid)
		for (Entity* item : v)
		{
			if (item->solid && location.intersects(item->location))
			{
				moveBack();
				anim = IDLE;
				frame_id = 0;
				updateSubrect();
				break;
			}
		}
		if (frame_delay)
			frame_delay--;
		else
		{
			frame_delay = 7;
			frame_id++;
			updateSubrect();
		}
}

void Entity::updateSubrect()
{
	sprite.setTextureRect(sf::IntRect(subrect.width * (frame_id % 8),
		subrect.height * (direction + 4 * (int)anim), subrect.width, subrect.height));
}

void Entity::move(int x, int y)
{
	location_set(location.left + x, location.top + y, location.width, location.height);
}
void Entity::move()
{
	location_set(location.left + move_x, location.top + move_y, location.width, location.height);
}
void Entity::moveBack()
{
	location_set(location.left - move_x, location.top - move_y, location.width, location.height);
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::Sprite& Entity::sprite_get()
{
	return sprite;
}
