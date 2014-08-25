#pragma once

#include <SFML\Graphics.hpp>

#include "Scene.h"
#include "Ressource.h"

class MenuLevel : public Scene
{
public:
	MenuLevel(void);
	virtual ~MenuLevel(void) override;
	virtual void transition_in(sf::RenderWindow& window) override;
	virtual void transition_out(sf::RenderWindow& window) override;
	virtual void update(sf::Event& event, sf::RenderWindow& window, SceneName& index, std::vector<bool>& pressed_keys) override;
	virtual void draw(sf::RenderWindow& window) override;

private:
	sf::Sprite background;
};