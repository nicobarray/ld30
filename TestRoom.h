#pragma once

#include "Scene.h"
#include "Level.h"
#include "Prop.h"

class TestRoom : public Scene
{
public:
	TestRoom(void);
	TestRoom(SDL_Surface* tileset);
	virtual ~TestRoom(void);

	virtual void transition_in();
	virtual void transition_out();
	virtual void update(const SDL_Event& e, int index);
	virtual void draw(SDL_Surface* screen);

private:
	Level level;
	SDL_Surface* tileset;
};

