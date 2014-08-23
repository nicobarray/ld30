#include "GameEngine.h"

GameEngine::GameEngine(void)
	: quit(false)
{

}

GameEngine::~GameEngine(void)
{

}

void GameEngine::update(const SDL_Event& e)
{
	if (e.type == SDL_QUIT)
		quit = true;
}

// Blit sprites and stuffs on the window's surface
void GameEngine::draw(SDL_Surface* screen)
{

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