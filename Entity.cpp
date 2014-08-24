#include "Entity.h"

#define SCALE = 3


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

void Entity::texture_set(sf::Texture& tex)
{
	texture = tex;
}

void Entity::update()
{
	move_x = 0;
	move_y = 0;
	if (frame_delay)
		frame_delay--;
	else
	{
		frame_delay = 7;
		sprite.setTextureRect(sf::IntRect(subrect.width * (++frame_id % 8), subrect.height * direction, subrect.width, subrect.height));
		//std::cout << "Frame number: " << frame_id << '\n';
	}
}

void Entity::update(std::vector<Entity*> v)
{
	move();
	if (solid)
		for (Entity* item : v)
		{
			if (item->solid && location.intersects(item->location))
			{
				moveBack();
				break;
			}
		}
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