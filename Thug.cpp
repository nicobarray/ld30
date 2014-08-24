#include "Thug.h"

Thug::Thug(sf::Texture& t, Level* l, int x, int y)
	: Mob(t, l, x, y, 32, 32)
{
}


Thug::~Thug(void)
{
}

void Thug::update()
{
	Entity::update();

	if (!dead && anim != DEATH)
	{
		float x = box.left + box.width/2;
		float y = box.top + box.height/2;
		float x2 = x;
		float y2 = y;

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

			float m_x = x2 - x;
			float m_y = y2 - y;
			float speed = 1.3f;
			float dist = m_x * m_x + m_y * m_y + 1;
			dist  = sqrt(dist);

			if (dist < 66)//allonge-4
			{
				anim = ATTACK;
				move_x = 0;
				move_y = 0;
			}
			else
			{
				if (m_x)
					move_x = (speed * m_x) / dist;
				if (m_y)
					move_y = (speed * m_y) / dist;

				/*if (col_x && move_y < 0)
				move_y -= abs(move_x);
				if (col_x && move_y > 0)
				move_y += abs(move_x);
				if (col_y && move_x < 0)
				move_x -= abs(move_y);
				if (col_y && move_x > 0)
				move_x += abs(move_y);*/
			}
	}
}
