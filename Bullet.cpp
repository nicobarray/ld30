#include "Bullet.h"


Bullet::Bullet(sf::Texture& texture, int x, int y)
	: Prop(texture, x, y, 16, 16, false)
{
}

Bullet::~Bullet(void)
{
}

void Bullet::update(std::vector<Entity*> ground, std::vector<Entity*> items)
{
	Entity::update(ground, items);
	if (anim != DEATH)
	{
		for (Entity* tile : ground)
		{
			if (tile->solid_get() && box.intersects(tile->location_get()))
			{
				anim = DEATH;
				move_x = 0;
				move_y = 0;
				break;
			}
		}
		for (Entity* prop : items)
		{
			if (prop != this && prop->solid_get() && box.intersects(prop->box_get()))
			{
				if (dynamic_cast<Player*> (prop))
				{
					anim = DEATH;
					move_x = 0;
					move_y = 0;
					prop->die(1);
				}
			}
		}
	}
}