#pragma once

#include "Scene.h"
#include "Ressource.h"

class MenuMain : public Scene
{
public:
	MenuMain(void);
	virtual ~MenuMain(void) override;
	virtual void transition_in(sf::RenderWindow& window) override;
	virtual void transition_out(sf::RenderWindow& window) override;
	virtual void update(sf::Event& event, sf::RenderWindow& window, SceneName& index, std::vector<bool>& pressed_keys) override;
	virtual void draw(sf::RenderWindow& window) override;
	
private:
	sf::Sprite background;
};

