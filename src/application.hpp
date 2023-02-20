#pragma once

#include "window.hpp"
#include "render.hpp"
#include "gameloop.hpp"
#include "globals.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// std
#include <iostream>

namespace snake {
class snakeApplication
{
public:
    int run();

private:
    void init();
    snakeWindow window;
    snakeGameloop gameloop;
    snakeRenderer renderer;
    snakeText text;
    snakeGlobals globals;

};
}
