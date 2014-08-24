#pragma once

#include <vector>
#include <iostream>

#include <SFML\Graphics.hpp>

/*
	Classe abstraite
	Represente tous les objets/creatures/drops
*/

enum animation
{
	IDLE = 0,
	RUN
};

enum direction_id
{
	SOUTH = 0,
	EAST,
	NORTH,
	WEST
};

class Entity
{
public:
	Entity(sf::Texture& texture, int x, int y, int w, int h, bool s);
	virtual ~Entity(void);

	void location_set(int x, int y, int w, int h);
	sf::IntRect& location_get();
	void texture_set(sf::Texture& texture);
	
	virtual void update();
	void update(std::vector<Entity*>);
	void draw(sf::RenderWindow& window);

	bool contact(Entity *e);
	void move(int x, int y);
	void move();
	void moveBack();

	void updateSubrect();

protected:
	sf::IntRect location;
	sf::IntRect subrect;
	sf::Texture& texture;
	sf::Sprite sprite;
	bool solid;
	int move_x, move_y, direction, frame_id, frame_delay;
	animation anim;
};

