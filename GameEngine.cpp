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

	res.load_image("../ld30/res/tileset-garden.png");
	res.load_image("../ld30/res/tileset-fairy.png");
	res.load_image("../ld30/res/drop-health.png");
	res.load_image("../ld30/res/hero.png");
	res.load_image("../ld30/res/imp.png");
	res.load_image("../ld30/res/spitter.png");
	res.load_image("../ld30/res/thug.png");
	res.load_image("../ld30/res/spit.png");
	res.load_image("../ld30/res/woosh.png");
	res.load_image("../ld30/res/crate.png");
	res.load_image("../ld30/res/dust.png");
	res.load_image("../ld30/res/title.png");
	res.load_image("../ld30/res/controls.png");
	res.load_image("../ld30/res/game-over.png");
	res.load_image("../ld30/res/portal1.png");
	res.load_image("../ld30/res/portal2.png");
	res.load_image("../ld30/res/door.png");
	res.load_image("../ld30/res/hud-health.png");
	res.load_image("../ld30/res/hud-health-bar.png");
	res.load_image("../ld30/res/hud-energy.png");
	res.load_image("../ld30/res/hud-energy-empty.png");
	res.load_image("../ld30/res/exit1.png");
	res.load_image("../ld30/res/exit2.png");
	res.load_image("../ld30/res/mystery.png");

	// Load musics here

	res.load_wav("../ld30/res/teleport.wav");
	res.load_wav("../ld30/res/shot.wav");
	res.load_wav("../ld30/res/hit.wav");
	res.load_wav("../ld30/res/foot.wav");


	// Load musics here

	snd.load_music("../ld30/res/real_music.wav");
	snd.load_music("../ld30/res/fairy_music.wav");

	// Add scenes here

	scenes.push_back(new MenuMain());
	scenes.push_back(new MenuLevel());
	scenes.push_back(new Game());
	scenes.push_back(new EndScreen());

	// Test room (debug only)
	scenes.push_back(new TestRoom(res.texture_get((int)TILESET1)));

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

#ifdef WIN32
/*
** Entry point for a Win32 application
** Allows to build the program for Windows
*/
#include <windows.h>

int WINAPI
	wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
/*
** Generic entry point.
** Should work for a Unix build (Mac OS compatible?)
*/
int main()
#endif
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