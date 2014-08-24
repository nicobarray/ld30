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

	void location_set(float x, float y);
	sf::IntRect& location_get();
	void texture_set(sf::Texture& texture);
	bool dead_get();
	sf::IntRect box_get();
	animation anim_get();
	
	virtual void update();
	virtual void update(std::vector<Entity*> ground, std::vector<Entity*> items);
	void draw(sf::RenderWindow& window);

	bool contact(Entity *e);
	void move(float x, float y);
	void move(std::vector<Entity*> ground, std::vector<Entity*> items);
	void moveBack();

	sf::Sprite& sprite_get();
	void solid_set(bool b);
	void updateSubrect();

	virtual void die(int n);

protected:
	sf::IntRect location;
	sf::IntRect subrect;
	sf::Texture& texture;
	sf::Sprite sprite;
	sf::IntRect box;
	bool solid, dead, col_x, col_y;
	int move_x, move_y;
	int direction, frame_id, frame_delay, invu;
	animation anim;

	//DEBUG
	sf::RectangleShape bb;
};

