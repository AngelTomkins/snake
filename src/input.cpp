#include "input.hpp"

#include <SDL2/SDL_mouse.h>
#include <cmath>
#include <iostream>

namespace snake {

void snakeInput::input(controller * p_playerController, SDL_Event * p_e, uint32_t * p_windowSizeX, uint32_t * p_windowSizeY)
{
    // Change the direction of the snake based on what keys are being pressed
    if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
        p_playerController->dir = 'U';
	return;
    } else if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
        p_playerController->dir = 'D';
	return;
    } else if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
        p_playerController->dir = 'L';
	return;
    } else if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
        p_playerController->dir = 'R';
	return
    }

    uint32_t button;
    int x, y {0};
    button = SDL_GetMouseState(&x,&y);
    x -= *p_windowSizeX / 2;
    y -= *p_windowSizeY / 2;

    if ((button & SDL_BUTTON_LMASK) != 0){
        if (abs(x) > abs(y)){
            if (x > 0){
                p_playerController->dir = 'R';
            } else {
                p_playerController->dir = 'L';
            }
        } else if (abs(x) < abs(y)){
            if (y > 0){
                p_playerController->dir = 'D';
            } else {
                p_playerController->dir = 'U';
        }
        return;
        }
    }


}
}
