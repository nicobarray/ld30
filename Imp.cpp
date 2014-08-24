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

	/*for (Entity* e : parent->items_get())
		if (dynamic_cast<Player*> (e))
		{
			x2 = e->location_get().left;
			y2 = e->location_get().top;
		}*/

	move_x = x2 - x;
	move_y = y2 - y;
}
