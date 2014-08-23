#include "Entity.h"


Entity::Entity(SDL_Surface* t, int x, int y, int w, int h, bool s)
	: location(new SDL_Rect())
	, subrect(new SDL_Rect())
	, texture(t)
	, solid(s)
	, b(0,0,0,0)
	, move_x(0)
	, move_y(0)
	, direction(0)
	, frame_id(0)
	, frame_delay(7)
{
	location_set(x, y, w, h);
	subrect->x = 0;
	subrect->y = 0;
	subrect->w = w;
	subrect->h = h;
}

Entity::~Entity(void)
{
	delete location;
	delete subrect;
}

void Entity::location_set(int x, int y, int w, int h)
{
	location->x = x;
	location->y = y;
	location->w = w;
	location->h = h;
	b = Box(x, y, x+w, y+h);
}

void Entity::texture_set(SDL_Surface* tex)
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
		subrect->x = subrect->w * (++frame_id % 8);
		std::cout << "Frame number: " << frame_id << '\n';
	}
}
void Entity::update(std::vector<Entity*> v)
{
	move();
	if (solid)
		for (Entity* item : v)
		{
			if (item->solid && b.collide(item->b))
			{
				moveBack();
				break;
			}
		}
}

bool Entity::contact(Entity* e)
{
	return b.collide(e->b);
}

void Entity::move(int x, int y)
{
	location_set(location->x + x, location->y + y, location->w, location->h);
}
void Entity::move()
{
	location_set(location->x + move_x, location->y + move_y, location->w, location->h);
}
void Entity::moveBack()
{
	location_set(location->x - move_x, location->y - move_y, location->w, location->h);
}

void Entity::draw(SDL_Surface* screen)
{
	SDL_BlitSurface(texture, subrect, screen, location);
}
