#pragma once

#include<SDL.h>
#include<iostream>

class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);

	void update();
	void draw(SDL_Surface* screen);

	bool quit_get();

private:
};

