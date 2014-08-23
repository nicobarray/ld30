#pragma once

#include<SDL.h>
#include<iostream>
#include<chrono>

class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);

	void update(const SDL_Event& e);
	void draw(SDL_Surface* screen);

	bool quit_get();

private:
	bool quit;
};

