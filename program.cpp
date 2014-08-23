#include "program.h"

program::program(void)
{
}

program::~program(void)
{
}

int main(int argc, char **argv){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	while (true)
	{

	}

	SDL_Quit();

	return 0;
}