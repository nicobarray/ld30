#include "Entity.h"

#define SCALE = 3

int abs(int n)
{
	if (n > 0)
		return n;
	else
		return -n;
}

Entity::Entity(sf::Texture& texture, int x, int y, int w, int h, bool s)
	: location(x * 3, y * 3, w * 3, h * 3)
	, subrect(0, 0, w, h)
	, texture(texture)
	, sprite(texture, sf::IntRect(0, 0, w, h))
	//, box(x * 3+ (w*3) /4, y * 3 + (h * 3)/2, (w*3)/2, (h*9)/8)
	, box(x * 3+ (w*3) /4+1, y * 3 + (h * 3)/2, (w*3)/2-2, (h*3)/2)
	, solid(s)
	, dead(false)
	, invu(0)
	, move_x(0)
	, move_y(0)
	, direction(0)
	, frame_id(0)
	, frame_delay(7)
	, anim(IDLE)
{
	location_set(x*3, y*3);
	sprite.setScale(3, 3);

	bb = sf::RectangleShape(sf::Vector2f(box.width, box.height));
	bb.setFillColor(sf::Color(0,0,0, 0));
	bb.setOutlineColor(sf::Color(255,0,0, 255));
	bb.setOutlineThickness(2);
	bb.setPosition(sf::Vector2f(box.left, box.top));

}

Entity::~Entity(void)
{
}

void Entity::location_set(int x, int y)
{
	box.left = box.left - location.left + x;
	box.top = box.top - location.top + y;
	location.left = x;
	location.top = y;
	sprite.setPosition(x, y);

	bb = sf::RectangleShape(sf::Vector2f(box.width, box.height));
	bb.setFillColor(sf::Color(0,0,0, 0));
	bb.setOutlineColor(sf::Color(255,0,0, 255));
	bb.setOutlineThickness(2);
	bb.setPosition(sf::Vector2f(box.left, box.top));
}
sf::IntRect& Entity::location_get()
{
	return location;
}
void Entity::texture_set(sf::Texture& tex)
{
	texture = tex;
}
bool Entity::dead_get()
{
	return dead;
}
sf::IntRect Entity::box_get()
{
	return box;
}
animation Entity::anim_get()
{
	return anim;
}

void Entity::update()
{
	if (!dead && anim != DEATH)
	{
		move_x = 0;
		move_y = 0;
	}
}

void Entity::update(std::vector<Entity*> ground, std::vector<Entity*> items)
{
	if (!dead)
	{
		if (move_y != 0 || move_x != 0)
		{
#pragma region move
			if (anim == IDLE)
			{
				frame_id = 0;
				anim = RUN;
			}
			if (move_y > 0 && move_y > abs(move_x))
				direction = SOUTH;
			else if (move_y < 0 && -move_y > abs(move_x))
				direction = NORTH;
			else if (move_x > 0 && move_x > abs(move_y))
				direction = EAST;
			else if (move_x < 0 && -move_x > abs(move_y))
				direction = WEST;
			move(ground, items);
			updateSubrect();  
#pragma endregion
		}
		else if (anim == RUN)
			anim = IDLE;

		if (frame_delay)
			frame_delay--;
		else
		{
			frame_delay = 7;
			frame_id++;
			updateSubrect();
			if (frame_id % 8 == 0 && anim == ATTACK)
				anim = IDLE;
			if (frame_id % 5 == 0 && anim == DEATH)
			{
				move_x = 0;
				move_y = 0;
			}
			if (frame_id % 8 == 0 && anim == DEATH)
			{
				anim = IDLE;
				dead = true;
			}
		}
	}
}

void Entity::updateSubrect()
{
	sprite.setTextureRect(sf::IntRect(subrect.width * (frame_id % 8),
		subrect.height * (direction + 4 * (int)anim), subrect.width, subrect.height));
}

void Entity::die(int n)
{
	dead = true;
}

void Entity::move(int x, int y)
{
	location_set(location.left + x, location.top + y);
}
void Entity::move(std::vector<Entity*> ground, std::vector<Entity*> items)
{
	move(move_x, 0);
	for (Entity* tile : ground)
	{
		if (tile->solid && box.intersects(tile->location))
		{
			move(-move_x, 0);
			move_x = 0;
			break;
		}
	}
	for (Entity* prop : items)
	{
		if (prop->solid && box.intersects(prop->location))
		{
			move(-move_x, 0);
			move_x = 0;
			break;
		}
	}


	move(0, move_y);
	for (Entity* tile : ground)
	{
		if (tile->solid && box.intersects(tile->location))
		{
			move(0, -move_y);
			move_y = 0;
			break;
		}
	}
	for (Entity* prop : items)
	{
		if (prop->solid && box.intersects(prop->location))
		{
			move(0, -move_y);
			move_y = 0;
			break;
		}
	}
}
void Entity::moveBack()
{
	location_set(location.left - move_x, location.top - move_y);
}

void Entity::draw(sf::RenderWindow& window)
{
	if (!dead && !((invu/7)%2))
	{
		window.draw(sprite);
		if (move_x || move_y)
			window.draw(bb);
	}
}

sf::Sprite& Entity::sprite_get()
{
	return sprite;
}

void Entity::solid_set(bool b)
{
	solid = b;
}
