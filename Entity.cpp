#include "Entity.h"


Entity::Entity(void)
	: location(new SDL_Rect())
	, texture(nullptr)
	, solid(false)
	, b(0,0,0,0)
{
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

bool Entity::contact(Entity* e)
{
	return b.collide(e->b);
}