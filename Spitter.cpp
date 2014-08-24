#include "Spitter.h"

Spitter::Spitter(sf::Texture& t, Level* l, int x, int y)
	: Mob(t, l, x, y, 32, 32)
	, shots()
{
	sprite.setColor(sf::Color(255, 0, 0, 255));
}

Spitter::~Spitter(void)
{
}

void Spitter::update()
{
	move_x = 0;
	move_y = 0;

	if (!dead && anim != DEATH && anim != SWITCHING)
	{
		if (anim == ATTACK)
		{
			if (frame_id == 7 && frame_delay == 6)
				shoot();
		}
		else
		{
			float x = box.left + box.width/2;
			float y = box.top + box.height/2;
			float x2 = x;
			float y2 = y;

			for (Entity* e : parent->items_get())
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

			if (dist < 16*10)//allonge-4
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
}

void Spitter::shoot()
{
	if (shots.size() < 5)
	{
		std::cout << "Shoot !\n";
		Ressource& res = Ressource::getInstance();
		Prop* bullet = new Prop(res.texture_get(SWITCH), box.left, box.top, 16, 16, false);

		float x = box.left + box.width/2;
		float y = box.top + box.height/2;
		float x2 = x;
		float y2 = y;

		for (Entity* e : parent->items_get())
		{
			if (dynamic_cast<Player*> (e))
			{
				x2 = e->box_get().left + e->box_get().width/2;
				y2 = e->box_get().top + e->box_get().height/2;
			}
		}

		float m_x = x2 - x;
		float m_y = y2 - y;
		float speed = 7;
		float dist = m_x * m_x + m_y * m_y;
		dist  = sqrt(dist);

		bullet->speed_set((speed * m_x) / dist, (speed * m_y) / dist);
		bullet->location_set(box.left + 5 * ((speed * m_x) / dist), box.top + 5 * ((speed * m_y) / dist));
		parent->addEntity(bullet);
		shots.push_back(bullet);
	}
}
