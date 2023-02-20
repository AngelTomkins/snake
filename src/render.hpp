#pragma once

#include <SDL2/SDL.h>

// std
#include <cstdint>
#include <vector>

namespace snake{
struct Vector2 {
    float x,y;
};

class snakeRenderer{
public:
    void init(SDL_Window * p_window, uint32_t * p_windowSizeX, uint32_t * p_windowSizeY,uint8_t * p_game_sizeX, uint8_t * p_game_sizeY);

    void render(uint8_t & p_x, uint8_t & p_y);
    void clear();

    //getter
    SDL_Renderer * getRenderer(){ return renderer; }

private:
    SDL_Renderer * renderer;
    const uint32_t *windowSizeX, *windowSizeY;
    const uint8_t *game_sizeX, *game_sizeY;

    Vector2 scale_factor;
};
}