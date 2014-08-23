#include "program.h"

program::program(void)
{
}

program::~program(void)
{
}

void program::initialize()
{

}

void program::update()
{

}

void program::draw(SDL_Surface* screen)
{

}

int main(int argc, char **argv){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	program program;

	SDL_Quit();

	return 0;
}