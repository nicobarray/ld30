#include "TestRoom.h"

TestRoom::TestRoom(sf::Texture& t)
	: level("map/gliched.tmx", t)
{
	Ressource& res = Ressource::getInstance();
	level.addEntity(new Imp(res.texture_get((int)IMP), dynamic_cast<Level *const> (this), 16, 16));
	level.addEntity(newPotion(res.texture_get((int)DROPHEALTH), 16, 16));
	level.addEntity(new Player(res.texture_get((int)HERO), 0, 0));
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