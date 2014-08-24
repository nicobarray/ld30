#include "Spitter.h"

Spitter::Spitter(sf::Texture& t, Level* l, int x, int y)
	: Mob(t, l, x, y, 32, 32)
{
	sprite.setColor(sf::Color(255, 0, 0, 255));
}

Spitter::~Spitter(void)
{
}

void Spitter::update()
{
	Entity::update();

	if (!dead && anim != DEATH && anim != SWITCHING)
	{
		float x = box.left + box.width/2;
		float y = box.top + box.height/2;
		float x2 = x;
		float y2 = y;

		if (parent)
			for (Entity* e : parent->items_real_get())
			{
				if (dynamic_cast<Player*> (e))
				{
					x2 = e->box_get().left + e->box_get().width/2;
					y2 = e->box_get().top + e->box_get().height/2;
				}
			}

			float m_x = x2 - x;
			float m_y = y2 - y;
			float speed = 1.5f;
			float dist = m_x * m_x + m_y * m_y;
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
			}
	}
}
