#include "TestRoom.h"

TestRoom::TestRoom(SDL_Surface* tileset)
	: level("map/Test map ld30.tmx")
	, tileset(tileset)
{

}


TestRoom::~TestRoom(void)
{
}

void TestRoom::transition_in()
{

}

void TestRoom::transition_out()
{

}

void TestRoom::update(const SDL_Event& e, int index)
{

}

void TestRoom::draw(SDL_Surface* screen)
{
	SDL_Rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = screen->w;
	rect.h = screen->h;
	
	SDL_Rect srect;

	srect.x = 16;
	srect.y = 0;
	srect.w = 16;
	srect.h = 16;

	SDL_BlitSurface(tileset, &srect, screen, &rect);
}