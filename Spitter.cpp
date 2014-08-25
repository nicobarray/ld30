#include "Spitter.h"

Spitter::Spitter(sf::Texture& t, Level* l, int x, int y)
	: Mob(t, l, x, y, 32, 32)
	, shots()
	, bullet_x(0)
	, bullet_y(0)
{
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
			if (frame_id == 4 && frame_delay == 6)
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
			float dist = m_x * m_x + m_y * m_y;
			dist  = sqrt(dist);

			if (dist < 16*20)
			{
				direction_set();
				anim = ATTACK;
				frame_id = 0;
				frame_delay = 7;
				//std::cout << "Shoot at "<< bullet_x << ", " << bullet_y <<"\n";
				bullet_x = (8 * m_x) / dist;
				bullet_y = (8 * m_y) / dist;
				move_x = 0;
				move_y = 0;
			}
			else
			{
				if (m_x)
					move_x = (1.5f * m_x) / dist;
				if (m_y)
					move_y = (1.5f * m_y) / dist;
			}
		}
	}
}
void Spitter::update(std::vector<Entity*> ground, std::vector<Entity*> items)
{
	Entity::update(ground, items);
	for (Entity* p : shots)
		p->update(ground, items);
}
void Spitter::draw(sf::RenderWindow& window)
{
	Entity::draw(window);
	for (Entity* p : shots)
		p->draw(window);
}

void Spitter::shoot()
{
	Ressource& res = Ressource::getInstance();
	Bullet* bullet = new Bullet(res.texture_get(SPIT), box.left, box.top);

	std::cout << "Shoot at "<< bullet_x << ", " << bullet_y <<"\n";
	bullet->speed_set(bullet_x, bullet_y);
	bullet->location_set(box.left + 7 * bullet_x, box.top + 7 * bullet_y);
	//parent->addEntity(bullet);
	if (shots.size() < 5)
	{
		std::cout << "Shoot !"<< std::endl;
		shots.push_back(bullet);
	}
	else
	{
		std::sort(shots.begin(), shots.end(), compare);
		shots[4] = bullet;
	}
}
