#pragma once
#include <iostream>
#include <SDL.h>

class program
{
public:
	program(void);
	~program(void);
	void initialize();
	void update();
	void draw(SDL_Surface* screen);
};
