#include "application.hpp"


namespace snake {

int snakeApplication::run()
{
    init();
    // snakeGameloop gameloop(globals.getGameSizeX(), globals.getGameSizeY());
    gameloop.runloop(&renderer, &window, globals.getWindowSizeX(), globals.getWindowSizeY(), globals.getGameSizeX(), globals.getGameSizeY());
    return 0;
}

void snakeApplication::init()
{
    window.init(globals.getWindowName(), globals.getWindowSizeX(), globals.getWindowSizeY());
    renderer.init(window.getWindow(), globals.getWindowSizeX(), globals.getWindowSizeY(), globals.getGameSizeX(), globals.getGameSizeY());

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << "Error Initializing SDL: " << SDL_GetError() << '\n';
    if (TTF_Init() != 0)
        std::cerr << "Error Initializing TTF: " << SDL_GetError() << '\n';
}
}