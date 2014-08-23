#pragma once

#include "Scene.h"

class TestRoom : public Scene
{
public:
	TestRoom(void);
	virtual ~TestRoom(void);

	virtual void transition_in();
	virtual void transition_out();
	virtual void update(const SDL_Event& e, int index);
	virtual void draw(SDL_Surface* screen);
};

