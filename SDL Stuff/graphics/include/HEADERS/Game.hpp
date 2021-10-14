#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>

enum class GameState {PLAY, EXIT};

class Game {
    public:
        Game();
        ~Game();

        void run();
    private:
        void initSystems(const char* title, int x, int y, int w, int h, Uint32 flags);
        void gameLoop();
        void processInput();

        SDL_Window* _window;
        int _screenWidth;
        int _screenHeight;
        GameState _gameState;
};