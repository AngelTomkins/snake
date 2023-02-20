#include "window.hpp"
#include "globals.hpp"
#include <SDL2/SDL_video.h>

namespace snake{

void snakeWindow::init(std::string p_windowName, uint32_t * p_windowSizeX, uint32_t * p_windowSizeY)
{
    windowSizeX = p_windowSizeX;
    windowSizeY = p_windowSizeY;


    window = SDL_CreateWindow(p_windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, *windowSizeX, *windowSizeY, SDL_WINDOW_SHOWN);
    SDL_SetWindowResizable(window, SDL_bool(true));
}

void snakeWindow::resized(int *p_x, int *p_y)
{
    *windowSizeX = *p_x;
    *windowSizeY = *p_y;
    
}


void snakeWindow::cleanup()
{
    SDL_DestroyWindow(window);
}
}