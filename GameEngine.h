#pragma once

#include<SFML/Graphics.hpp>

#include<iostream>
#include<vector>

#include "Game.h"

#include "Scene.h"
#include "Ressource.h"
#include "TestRoom.h"
#include "MenuLevel.h"
#include "MenuMain.h"
#include "EndScreen.h"

class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);
 
	void update(sf::Event& event, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

	bool quit_get();

private:
	bool quit;
	SceneName index;
	SceneName last_scene;
	std::vector<Scene*> scenes;
};

