#include "Entity.h"


Entity::Entity(sf::Texture& texture, int x, int y, int w, int h, bool s)
	: location(x, y, w, h)
	, subrect(0, 0, w, h)
	, texture(texture)
	, solid(s)
	, move_x(0)
	, move_y(0)
	, direction(0)
	, frame_id(0)
	, frame_delay(7)
{
	location_set(x, y, w, h);
}

Entity::~Entity(void)
{
}

void Entity::location_set(int x, int y, int w, int h)
{
	/*location->x = x;
	location->y = y;
	location->w = w;
	location->h = h;*/
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
		subrect.left = subrect.width * (++frame_id % 8);
		std::cout << "Frame number: " << frame_id << '\n';
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
		
	sf::Sprite sprite(texture, subrect);
		//sprite.move(x, y);
}

void Entity::move(int x, int y)
{
	location_set(location.left + x, location.top + y, location.width, location.height);
}
void Entity::move()
{
	//location_set(location->x + move_x, location->y + move_y, location->w, location->h);
}
void Entity::moveBack()
{
	//location_set(location->x - move_x, location->y - move_y, location->w, location->h);
}

void Entity::draw(sf::RenderWindow& window)
{
	sf::Sprite sprite(texture, subrect);
	//sprite.draw(window, sf::RenderStates::Default);
}
