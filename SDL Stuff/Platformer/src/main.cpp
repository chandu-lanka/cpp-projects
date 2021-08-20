#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "Hey.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init has failed... Error: " << SDL_GetError() << std::endl;

	RenderWindow window("Game", 1280, 720);
	SDL_Texture* grassTexture = window.loadTexture("res/imgs/ground_grass_1.png");
	bool gameRunning = true;
	SDL_Event event;
	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		window.render(grassTexture);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}