#include "TestRoom.h"

TestRoom::TestRoom(void)
	: level()
{

	level.addEntity(new Prop());
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

}