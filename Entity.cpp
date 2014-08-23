#include "Entity.h"


Entity::Entity(void)
	: location(new SDL_Rect()), texture(nullptr)
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
}

void Entity::texture_set(SDL_Surface* tex)
{
	texture = tex;
}