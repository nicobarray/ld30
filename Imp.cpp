#include "Imp.h"


Imp::Imp(sf::Texture& t, Level* l, int x, int y)
	: Mob(t, l, x, y, 32, 32)
{
}


Imp::~Imp(void)
{
}

void Imp::update()
{
	Entity::update();

	if (!dead && anim != DEATH)
	{
		int x = box.left + box.width/2;
		int y = box.top + box.height/2;
		int x2 = x;
		int y2 = y;

		if (parent)
			for (Entity* e : parent->items_get())
			{
				//std::cout << "Checking item at " << e->location_get().left << ";" << e->location_get().top << "\n";
				if (dynamic_cast<Player*> (e))
				{
					x2 = e->box_get().left + e->box_get().width/2;
					y2 = e->box_get().top + e->box_get().height/2;
				}
			}

			move_x = x2 - x;
			move_y = y2 - y;
			int speed = 2;
			int dist = move_x * move_x + move_y * move_y;
			dist  = sqrt(dist);
			if (dist < 60)//allonge-4
			{
				anim = ATTACK;
				move_x = 0;
				move_y = 0;
			}
			else
			{
				if (move_x)
					move_x = (speed * move_x) / dist;
				if (move_y)
					move_y = (speed * move_y) / dist;
			}
	}
}
