#include "TestRoom.h"

TestRoom::TestRoom(sf::Texture& t)
	: level("map/level1.tmx", Ressource::getInstance().texture_get((int)TILESET1), t)
{
	Ressource& res = Ressource::getInstance();
	level.addRealEntity(new Imp(res.texture_get((int)IMP), &level, 16*10, 16*5));
	level.addRealEntity(newPotion(res.texture_get((int)DROPHEALTH), 16*5, 16*6));
	level.addRealEntity(new Player(res.texture_get((int)HERO), 0, 0));
	level.addRealEntity(newPotion(res.texture_get((int)DROPHEALTH), 16*8, 16*9));
}

TestRoom::~TestRoom(void)
{

}

void TestRoom::transition_in(sf::RenderWindow& window)
{

}

void TestRoom::transition_out(sf::RenderWindow& window)
{

}

void TestRoom::update(sf::Event& event, sf::RenderWindow& window, SceneName& index, std::vector<bool>& pressed_keys)
{
	level.update();
}

void TestRoom::draw(sf::RenderWindow& window)
{
	level.draw(window);
}