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
			if (tile->solid_get() > 1 && box.intersects(tile->location_get()))
			{
				hurt(1);
				move_x = 0;
				move_y = 0;
				break;
			}
		}
		for (Entity* prop : items)
		{
			if (prop != this && prop->real_get() == real && prop->solid_get() && box.intersects(prop->box_get()))
			{
				if (prop->anim_get() != SWITCH && dynamic_cast<Player*> (prop) && !prop->invu_get() > 0)
				{
					prop->hurt(1);
					prop->speed_set(move_x/2, move_y/2);
				}
				hurt(1);
				move_x = 0;
				move_y = 0;
			}
		}
	}
}