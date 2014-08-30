#include "GameEngine.h"

GameEngine::GameEngine(void)
	: quit(false)
	, index(MENU)
	, last_scene(ENDSCREEN)
	, scenes()
	, pressed_keys()
{
	Ressource& res = Ressource::getInstance();
	SoundPlayer& snd = SoundPlayer::getInstance();

	res.load_image("res/tileset-garden.png");
	res.load_image("res/tileset-fairy.png");
	res.load_image("res/drop-health.png");
	res.load_image("res/hero.png");
	res.load_image("res/imp.png");
	res.load_image("res/spitter.png");
	res.load_image("res/thug.png");
	res.load_image("res/spit.png");
	res.load_image("res/woosh.png");
	res.load_image("res/crate.png");
	res.load_image("res/dust.png");
	res.load_image("res/title.png");
	res.load_image("res/controls.png");
	res.load_image("res/game-over.png");
	res.load_image("res/portal1.png");
	res.load_image("res/portal2.png");
	res.load_image("res/door.png");
	res.load_image("res/hud-health.png");
	res.load_image("res/hud-health-bar.png");
	res.load_image("res/hud-energy.png");
	res.load_image("res/hud-energy-empty.png");
	res.load_image("res/exit1.png");
	res.load_image("res/exit2.png");
	res.load_image("res/mystery.png");

	// Load musics here

	res.load_wav("res/teleport.wav");
	res.load_wav("res/shot.wav");
	res.load_wav("res/hit.wav");
	res.load_wav("res/foot.wav");

	// Load musics here

	snd.load_music("res/real_music.wav");
	snd.load_music("res/fairy_music.wav");

	// Add scenes here

	scenes.push_back(new MenuMain());
	scenes.push_back(new MenuLevel());
	scenes.push_back(new Game());
	scenes.push_back(new EndScreen());

	for (int i = 0; i < (int) sf::Keyboard::KeyCount; ++i)
		pressed_keys.push_back(false);
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

	last_scene = index;

	scenes.at(index)->update(event, window, index, pressed_keys);
	SoundPlayer::getInstance().update();

	for (int i = 0; i < (int) sf::Keyboard::KeyCount; ++i)
	{
		if (!sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i))
			pressed_keys[i] = false;
	}
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

//#ifdef WIN32
///*
//** Entry point for a Win32 application
//** Allows to build the program for Windows
//*/
//#include <windows.h>
//
//int WINAPI
//	wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
//#else
///*
//** Generic entry point.
//** Should work for a Unix build (Mac OS compatible?)
//*/
int main()
// #endif
{
	std::srand(time(nullptr));
	// Our game engine
	GameEngine engine = GameEngine();

	sf::RenderWindow window(sf::VideoMode(480 * 2, 320 * 2), "LD30", sf::Style::Close | sf::Style::Titlebar);

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