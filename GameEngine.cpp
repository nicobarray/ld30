#include "GameEngine.h"

GameEngine::GameEngine(void)
{

}

GameEngine::~GameEngine(void)
{

}

void GameEngine::update()
{

}

// Blit sprites and stuffs on the window's surface
void GameEngine::draw(SDL_Surface* screen)
{
	
}

bool GameEngine::quit_get()
{
	return false;
}

int main(int argc, char** argv)
{
	bool success = true;
	bool quit = false;
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
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
					quit = true;
				engine.update();
			}

			engine.draw(screen);
			SDL_UpdateWindowSurface(window);
		}
	}

	SDL_Quit();
	return !success;
}