#include "render.hpp"
#include <SDL2/SDL_render.h>

#include <iostream>
#include <vector>

namespace snake{

void snakeRenderer::init(SDL_Window * p_window, uint32_t * p_windowSizeX, uint32_t * p_windowSizeY, uint8_t * p_game_sizeX, uint8_t * p_game_sizeY)
{
    renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);

    game_sizeX = p_game_sizeX;
    game_sizeY = p_game_sizeY;
    windowSizeX = p_windowSizeX;
    windowSizeY = p_windowSizeY;
}

void snakeRenderer::clear()
{
    //Clear screen
    SDL_SetRenderDrawColor( renderer, 0x25, 0x59, 0x02, 0xFF );
    SDL_RenderClear( renderer );
}
void snakeRenderer::render(uint8_t & p_x, uint8_t & p_y)
{
    scale_factor = {(float)*windowSizeX / (float)*game_sizeX, (float)*windowSizeY / (float)*game_sizeY };
    SDL_Rect fillRect { static_cast<int>((p_x - 1) * scale_factor.x),
                        static_cast<int>((p_y - 1) * scale_factor.y),
                        static_cast<int>(scale_factor.x),
                        static_cast<int>(scale_factor.y)};

    SDL_SetRenderDrawColor(renderer, 0xB9, 0x72, 0x1B, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);

    #if 0
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            switch (p_map[i][j]){
                case 1:
                    fillRect = {i * 40, j * 40, static_cast<int>(*windowSizeX) / 20, static_cast<int>(*windowSizeY) / 20};
                    SDL_SetRenderDrawColor(renderer, 0xB9, 0x72, 0x1B, 0xFF);
                    SDL_RenderFillRect(renderer, &fillRect);
                    break;
                case 2:
                    fillRect = {i * 40, j * 40, static_cast<int>(*windowSizeX) / 20, static_cast<int>(*windowSizeY) / 20};
                    SDL_SetRenderDrawColor(renderer, 0xCA, 0x46, 0x34, 0xFF);
                    SDL_RenderFillRect(renderer, &fillRect);
                    break;
            }
        }
    }
    #endif
}
}