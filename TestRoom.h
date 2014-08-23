#pragma once

#include "Scene.h"
#include "Level.h"
#include "Ressource.h"

#include "AllEntities.h"

class TestRoom : public Scene
{
public:
	TestRoom(SDL_Surface* t);
	virtual ~TestRoom(void);

	virtual void transition_in();
	virtual void transition_out();
	virtual void update(const SDL_Event& e, int index);
	virtual void draw(SDL_Surface* screen);

private:
	Level level;
};

