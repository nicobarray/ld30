#pragma once

#include <vector>
#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

/*
	Classe abstraite
	Represente tous les objets/creatures/drops
*/

enum animation
{
	IDLE = 0,
	RUN,
	ATTACK,
	DEATH
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

	void location_set(int x, int y);
	sf::IntRect& location_get();
	void texture_set(sf::Texture& texture);
	bool dead_get();
	sf::IntRect box_get();
	
	virtual void update();
	virtual void update(std::vector<Entity*> ground, std::vector<Entity*> items);
	void draw(sf::RenderWindow& window);

	bool contact(Entity *e);
	void move(int x, int y);
	void move();
	void moveBack();

	sf::Sprite& sprite_get();
	void updateSubrect();

	virtual void die(int n);

protected:
	sf::IntRect location;
	sf::IntRect subrect;
	sf::Texture& texture;
	sf::Sprite sprite;
	sf::IntRect box;
	bool solid, dead;
	int move_x, move_y, direction, frame_id, frame_delay;
	animation anim;

	//DEBUG
	sf::RectangleShape bb;
};

