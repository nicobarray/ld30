#pragma once

#include <vector>
#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "Ressource.h"
#include "SoundPlayer.h"

/*
	Classe abstraite
	Represente tous les objets/creatures/drops
*/

enum animation
{
	IDLE = 0,
	RUN,
	ATTACK,
	DEATH,
	SWITCHING
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
	bool solid_get();
	bool invu_get();
	sf::IntRect box_get();
	animation anim_get();
	void speed_set(int x, int y);

	void real_set(bool b);
	bool real_get();
	
	virtual void update() = 0;
	virtual void update(std::vector<Entity*> ground, std::vector<Entity*> items);
	virtual void draw(sf::RenderWindow& window);

	bool contact(Entity *e);
	void move(float x, float y);
	void move(std::vector<Entity*> ground, std::vector<Entity*> items);
	void moveBack();

	sf::Sprite& sprite_get();
	void solid_set(bool b);
	void updateSubrect();
	
	virtual void hurt(int n);
	virtual void dead_set(bool b);
	void switchWorld();

	void direction_set();

protected:
	sf::IntRect location;
	sf::IntRect subrect;
	sf::Texture& texture, switchTexture;
	sf::Sprite sprite, switchSprite;
	sf::IntRect box;
	bool dead, col_x, col_y, switched, real, gonna_end, end;
	int solid, move_x, move_y;
	int direction, frame_id, frame_delay, invu;
	animation anim;

	//DEBUG
	sf::RectangleShape bb;
};

bool compare (Entity *a, Entity *b);

