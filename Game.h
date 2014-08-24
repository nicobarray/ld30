#pragma once

#include "Scene.h"
#include "Ressource.h"
#include "Levels.h"
#include "Player.h"
#include "Imp.h"

class Game : public Scene
{
public:
	Game(void);
	virtual ~Game(void);
	virtual void transition_in(sf::RenderWindow& window) override;
	virtual void transition_out(sf::RenderWindow& window) override;
	virtual void update(sf::Event& event, sf::RenderWindow& window, int index) override;
	virtual void draw(sf::RenderWindow& window) override;

private:
	Level1 level1;
	Level2 level2;
	Player* player;
};

