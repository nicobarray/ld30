#pragma once

#include "Scene.h"
#include "Ressource.h"

class MenuMain : public Scene
{
public:
	MenuMain(void);
	virtual ~MenuMain(void);
	virtual void transition_in(sf::RenderWindow& window);
	virtual void transition_out(sf::RenderWindow& window);
	virtual void update(sf::Event& event, sf::RenderWindow& window, SceneName& index, std::vector<bool>& pressed_keys);
	virtual void draw(sf::RenderWindow& window);
	
private:
	sf::Sprite background;
};

