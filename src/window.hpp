#pragma once

#include <SDL2/SDL.h>

// std
#include <cstdint>
#include <string>

namespace snake {
class snakeWindow {

public:
    void init(std::string p_windowName, uint32_t * p_windowSizeX, uint32_t * p_windowSizeY);
    void cleanup();
    void resized(int *p_x, int *p_y);

    //getters
    SDL_Window * getWindow() { return window; }

private:
    SDL_Window * window;
    uint32_t *windowSizeX, *windowSizeY;


};

}