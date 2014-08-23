#include "GameEngine.h"

GameEngine::GameEngine(void)
	: quit(false)
	, index(0)
	, last_scene(0)
	, scenes()
{
	Ressource& res = Ressource::getInstance();

	res.load_image("../ld30/res/tileset-garden0.png");
	res.load_image("../ld30/res/drop-health.png");
	res.load_image("../ld30/res/imp.png");

	// Add scenes here

	// Test room (debug only)
	scenes.push_back(new TestRoom(res.texture_get((int)TILESET1)));
}

GameEngine::~GameEngine(void)
{

}

void GameEngine::update(const SDL_Event& e)
{
	if (e.type == SDL_QUIT)
		quit = true;

	if (last_scene != index)
	{
		scenes.at(last_scene)->transition_out();
		scenes.at(index)->transition_in();
	}

	scenes.at(index)->update(e, index);
	
	last_scene = index;
}

// Blit sprites and stuffs on the window's surface
void GameEngine::draw(SDL_Surface* screen)
{
	scenes.at(index)->draw(screen);

}

bool GameEngine::quit_get()
{
	return quit;
}

int main(int argc, char** argv)
{
	bool success = true;
	SDL_Window* window = nullptr;
	SDL_Surface* screen = nullptr;
	SDL_Event e;

	// Our game engine
	GameEngine engine = GameEngine();

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "SDL Init error: " << SDL_GetError() << std::endl;
		success = false;
	} 
	else
	{
		GameEngine engine = GameEngine();
		window = SDL_CreateWindow("ld30", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_SHOWN);

		if (!window)
		{
			std::cerr << "SDL Create Window error : " << SDL_GetError() << std::endl;
			success = false;
		}
		else
			screen = SDL_GetWindowSurface(window);
	}

	if (success)
	{
		while (!engine.quit_get())
		{

			while (SDL_PollEvent(&e) != 0)
			{
				engine.update(e);
			}

			engine.draw(screen);
			SDL_UpdateWindowSurface(window);
		}
	}

	SDL_Quit();
	return !success;
}