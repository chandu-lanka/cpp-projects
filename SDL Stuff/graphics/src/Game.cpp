#include "HEADERS/Game.hpp"

Game::Game() {
    _window = nullptr;
    _screenWidth = 1024;
    _screenHeight = 600;
    _gameState = GameState::PLAY;
}
Game::~Game() {}

void fatalError(std::string errorString) {
    std::cout << errorString << std::endl;
    std::cout << "Error any key to quit..." << std::endl;
    int tmp;
    std::cin >> tmp;
    SDL_Quit();
}

void Game::run() {
    initSystems("Graphics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
    gameLoop();
}

void Game::initSystems(const char* title, int x, int y, int w, int h, Uint32 flags) {
    // Init SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow(title, x, y, w, h, flags);
    if (_window == nullptr) {
        fatalError("SDL Window Couldn't Be Created");
    }
}

void Game::gameLoop() {
    while (_gameState != GameState::EXIT) {
        processInput();
    }
}

void Game::processInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
        }
    }

}