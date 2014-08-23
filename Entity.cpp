#include "Entity.h"


Entity::Entity(SDL_Surface* t, int x, int y)
	: location(new SDL_Rect())
	, texture(t)
	, solid(false)
	, b(0,0,0,0)
{
	location_set(x, y, t->w, t->h);
}

Entity::~Entity(void)
{
	delete location;
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

void Entity::draw(SDL_Surface* screen)
{
}

bool Entity::contact(Entity* e)
{
	return b.collide(e->b);
}

void Entity::move(int x, int y)
{
	location_set(location->x + x, location->y + y, location->w, location->h);
}

void Entity::draw(SDL_Surface* screen)
{
	SDL_BlitSurface(texture, nullptr, screen, location);
}
