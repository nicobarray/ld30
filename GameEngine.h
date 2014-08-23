#pragma once

#include<SDL.h>
#include<iostream>
#include<vector>

#include "Scene.h"
#include "TestRoom.h"
#include "Ressource.h"

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
	int index;
	int last_scene;
	std::vector<Scene*> scenes;
};

