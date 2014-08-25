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
					int x = box.left + box.width/2;
					int y = box.top + box.height/2;
					int x2 = x;
					int y2 = y;

					x2 = prop->box_get().left + prop->box_get().width/2;
					y2 = prop->box_get().top + prop->box_get().height/2;

					move_x = x2 - x;
					move_y = y2 - y;
					int speed = 2;
					int dist = move_x * move_x + move_y * move_y;
					dist  = sqrt(dist);

					if (!prop->invu_get() > 0)
					{
						prop->die(1);
						prop->speed_set((3.5f * move_x)/dist, (3.5f * move_y)/dist);
					}
				}
				anim = DEATH;
				move_x = 0;
				move_y = 0;
			}
		}
	}
}