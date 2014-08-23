#pragma once

#include<SDL.h>

class Scene
{
public:
	Scene(void);
	virtual ~Scene(void) = 0;
	virtual void transition_in() = 0;
	virtual void transition_out() = 0;
	virtual void update(const SDL_Event& e, int index) = 0;
	virtual void draw(SDL_Surface* screen) = 0;
};

