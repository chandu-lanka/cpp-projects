#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to be made lol..." << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
	{
		std::cout << "Failed To Load Img... " << SDL_GetError() << std::endl; 
	}

	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = 32;
	rect.h = 32;

	SDL_Rect dst;
	dst.x = 0;
	dst.y = 0;
	dst.w = 32;
	dst.h = 32;

	SDL_RenderCopy(renderer, p_tex, &rect, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}