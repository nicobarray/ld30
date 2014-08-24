#pragma once

#include<SFML/Graphics.hpp>

#include<iostream>
#include<vector>

#include "Scene.h"
#include "Ressource.h"
#include "TestRoom.h"

class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);
 
	void update(sf::Event& event);
	void draw(sf::RenderWindow& window);

	bool quit_get();

private:
	bool quit;
	int index;
	int last_scene;
	std::vector<Scene*> scenes;
};

