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

	int x = location.left;
	int y = location.top;
	int x2 = x;
	int y2 = y;

	if (parent)
		for (Entity* e : parent->items_get())
		{
			//std::cout << "Checking item at " << e->location_get().left << ";" << e->location_get().top << "\n";
			if (dynamic_cast<Player*> (e))
			{
				x2 = e->location_get().left;
				y2 = e->location_get().top;
			}
		}

		move_x = x2 - x;
		move_y = y2 - y;
		int speed = 2;
		int dist = move_x * move_x + move_y * move_y;
		dist  = sqrt(dist);

		if (move_x)
			move_x = (speed * move_x) / dist;
		if (move_y)
			move_y = (speed * move_y) / dist;
}
