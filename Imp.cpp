#include "Imp.h"


Imp::Imp(sf::Texture& t, Level* l, int x, int y)
	: Mob(t, l, x, y, 32, 32)
{
	frame_id = std::rand() % 8;
	attack.setBuffer(Ressource::getInstance().buffer_get((int)FOOT));
}

Imp::~Imp(void)
{
}

void Imp::update()
{
	move_x = 0;
	move_y = 0;

	if (!dead && anim != DEATH && anim != SWITCHING)
	{
		for (Entity* tile : parent->tiles_current_get())
		{
			if (tile->solid_get() && box.intersects(tile->location_get()))
			{
				hurt(0);
				break;
			}
		}
		if (anim != DEATH)
		{
			float x = box.left + box.width/2;
			float y = box.top + box.height/2;
			float x2 = x;
			float y2 = y;

			if (parent)
				for (Entity* e : parent->entities_get())
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
				float speed = 1.5f;
				float dist = m_x * m_x + m_y * m_y;
				dist  = sqrt(dist);

				if (dist < 66)//allonge-4
				{
					// play sound here
					attack.play();

					anim = ATTACK;
					move_x = 0;
					move_y = 0;
				}
				else if (dist < 16 * 20)
				{
					if (m_x)
						move_x = (speed * m_x) / dist;
					if (m_y)
						move_y = (speed * m_y) / dist;
				}
		}
	}
}
