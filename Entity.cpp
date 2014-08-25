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
	, box(x * 3+ (w*3) /4 + 2, y * 3 + (h * 3)/2+2, (w*3)/2-4, (h*3)/2-4)
	, solid(s)
	, dead(false)
	, col_x(false)
	, col_y(false)
	, real(true)
	, invu(0)
	, move_x(0)
	, move_y(0)
	, direction(0)
	, frame_id(0)
	, frame_delay(7)
	, anim(IDLE)
{
	Ressource& r = Ressource::getInstance();
	switchTexture = r.texture_get(SWITCH);
	switchSprite = sf::Sprite(switchTexture, location);
	location_set(x*3, y*3);
	sprite.setScale(3, 3);
	switchSprite.setScale(3, 3);

	bb = sf::RectangleShape(sf::Vector2f(box.width, box.height));
	bb.setFillColor(sf::Color(0,0,0, 0));
	bb.setOutlineColor(sf::Color(255,0,0, 255));
	bb.setOutlineThickness(2);
	bb.setPosition(sf::Vector2f(box.left, box.top));
}

Entity::~Entity(void)
{
}

void Entity::location_set(float x, float y)
{
	box.left = box.left - location.left + x;
	box.top = box.top - location.top + y;
	location.left = x;
	location.top = y;
	sprite.setPosition(location.left, location.top);
	switchSprite.setPosition(location.left, location.top);

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
bool Entity::solid_get()
{
	return solid;
}
bool Entity::invu_get()
{
	return invu;
}
sf::IntRect Entity::box_get()
{
	return box;
}
animation Entity::anim_get()
{
	return anim;
}
void Entity::speed_set(int x, int y)
{
	move_x = x;
	move_y = y;
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
			if (anim != DEATH)
				direction_set();

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
			if (frame_id % 4 == 0 && anim == DEATH)
			{
				move_x = 0;
				move_y = 0;
			}
			if (frame_id % 8 == 0 && anim == DEATH)
			{
				anim = IDLE;
				dead = true;
			}
			if (frame_id % 8 == 0 && anim == SWITCHING)
			{
				anim = IDLE;
				real = !real;
			}
		}
	}
}
void Entity::updateSubrect()
{
	sprite.setTextureRect(sf::IntRect(subrect.width * (frame_id % 8),
		subrect.height * (direction + 4 * (int)anim), subrect.width, subrect.height));
	switchSprite.setTextureRect(sf::IntRect(subrect.width * (frame_id % 8), 0, subrect.width, subrect.height));
}

void Entity::hurt(int n)
{
	anim = DEATH;
	frame_delay = 7;
	frame_id = 0;
}
void Entity::dead_set(bool b)
{
	dead = b;
}
void Entity::switchWorld()
{
	anim = SWITCHING;
	frame_delay = 7;
	frame_id = 0;
	SoundPlayer::getInstance().play((int)TELEPORT);
}
void Entity::direction_set()
{
	if (move_y > 0 && move_y > abs(move_x))
		direction = SOUTH;
	else if (move_y < 0 && -move_y > abs(move_x))
		direction = NORTH;
	else if (move_x > 0 && move_x > abs(move_y))
		direction = EAST;
	else if (move_x < 0 && -move_x > abs(move_y))
		direction = WEST;
}

void Entity::move(float x, float y)
{
	location_set(location.left + x, location.top + y);
}
void Entity::move(std::vector<Entity*> ground, std::vector<Entity*> items)
{
	move(move_x, 0);
	if (solid)
	{
		col_x = false;
		for (Entity* tile : ground)
		{
			if (tile->solid && box.intersects(tile->location))
			{
				move(-move_x, 0);
				move_x = 0;
				col_x = true;
				break;
			}
		}
		for (Entity* prop : items)
		{
			if (prop != this && prop->solid && prop->real == real && box.intersects(prop->box))
			{
				move(-move_x, 0);
				move_x = 0;
				col_x = true;
				break;
			}
		}
	}


	move(0, move_y);
	if (solid)
	{
		col_y = false;
		for (Entity* tile : ground)
		{
			if (tile->solid && box.intersects(tile->location))
			{
				move(0, -move_y);
				move_y = 0;
				col_y = true;
				break;
			}
		}
		for (Entity* prop : items)
		{
			if (prop != this && prop->solid && prop->real == real && box.intersects(prop->box))
			{
				move(0, -move_y);
				move_y = 0;
				col_y = true;
				break;
			}
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
		if (anim == SWITCHING)
			window.draw(switchSprite);
		else
			window.draw(sprite);
		//if (anim != IDLE)
		//	window.draw(bb);
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

bool compare (Entity *a, Entity *b)
{
	if (a->dead_get())
		return false;
	else
		return a->location_get().top < b->location_get().top;
}

void Entity::real_set(bool b)
{
	real = b;
}
bool Entity::real_get()
{
	return real;
}
