#pragma once

#include <SDL2/SDL.h>

#include "playercontroller.hpp"

namespace snake {
class snakeInput{
public:
    void input(controller * p_playerController, SDL_Event * p_e, uint32_t * p_windowSizeX, uint32_t * p_windowSizeY);

private:
    const uint8_t *state = SDL_GetKeyboardState(nullptr);

};

}