#pragma once

#include <SFML\Graphics.hpp>

#include "scene.h"
#include "Ressource.h"

class EndScreen :
	public Scene
{
public:
	EndScreen(void);
	~EndScreen(void);
	virtual void transition_in(sf::RenderWindow& window) override;
	virtual void transition_out(sf::RenderWindow& window) override;
	virtual void update(sf::Event& event, sf::RenderWindow& window, SceneName& index) override;
	virtual void draw(sf::RenderWindow& window) override;
	
private:
	sf::Sprite background;
};

