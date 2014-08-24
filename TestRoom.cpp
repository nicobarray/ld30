#include "TestRoom.h"

TestRoom::TestRoom(sf::Texture& t)
	: level("map/Test map ld30.tmx", t)
{
	Ressource& res = Ressource::getInstance();
	/*level.addEntity(new Imp(res.texture_get((int)IMP), 3*16, 5* 16));
	level.addEntity(newPotion(res.texture_get((int)DROPHEALTH), 6 * 16, 12 * 16));*/
}


TestRoom::~TestRoom(void)
{
}

void TestRoom::transition_in()
{

}

void TestRoom::transition_out()
{

}

void TestRoom::update(sf::Event& event, int index)
{
	level.update();
}

void TestRoom::draw(sf::RenderWindow& window)
{
	level.draw(window);
}