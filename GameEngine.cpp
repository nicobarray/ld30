#include "GameEngine.h"

GameEngine::GameEngine(void)
	: quit(false)
	, index(0)
	, last_scene(0)
	, scenes()
{
	Ressource& res = Ressource::getInstance();

	res.load_image("../ld30/res/tileset-garden0.png");
	res.load_image("../ld30/res/tileset-garden1.png");
	res.load_image("../ld30/res/drop-health.png");
	res.load_image("../ld30/res/hero.png");
	res.load_image("../ld30/res/imp.png");

	// Add scenes here

	scenes.push_back(new Game());

	// Test room (debug only)
	scenes.push_back(new TestRoom(res.texture_get((int)TILESET1)));
}

GameEngine::~GameEngine(void)
{

}

void GameEngine::update(sf::Event& event, sf::RenderWindow& window)
{
	if (false)
		quit = true;

	if (last_scene != index)
	{
		scenes.at(last_scene)->transition_out(window);
		scenes.at(index)->transition_in(window);
	}

	scenes.at(index)->update(event, window, index);

	last_scene = index;
}

// Blit sprites and stuffs on the window's surface
void GameEngine::draw(sf::RenderWindow& window)
{
	scenes.at(index)->draw(window);
}

bool GameEngine::quit_get()
{
	return quit;
}

int main(int argc, char** argv)
{
	// Our game engine
	GameEngine engine = GameEngine();

	sf::RenderWindow window(sf::VideoMode(16 *3 * 16, 16 * 3 * 16), "LD30");

	// Set rendering framerate at 60 frames per sec
	window.setFramerateLimit(60);

	// Main game loop - if the window is open, then loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		engine.update(event, window);
		window.clear();
		
		engine.draw(window);
		window.display();
	}

	return 0;
}