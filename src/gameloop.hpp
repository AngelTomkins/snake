#pragma once

#include <SDL2/SDL.h>

#include "render.hpp"
#include "window.hpp"
#include "playercontroller.hpp"
#include "text.hpp"
#include "input.hpp"

// std
#include <cstdint>
#include <vector>

namespace snake{
class snakeGameloop{
public:
//    snakeGameloop(uint8_t & p_gameSizeX, uint8_t & p_gameSizeY);
    void runloop(snakeRenderer * p_renderer, snakeWindow * p_window, uint32_t * p_windowSizeX, uint32_t * p_windowSizeY, uint8_t * p_gameSizeX, uint8_t * p_gameSizeY);

private:
    void init();
    void loopRender();
    void gameLogic();
    void updateScore(uint8_t p_score);

    uint8_t *game_sizeX, *game_sizeY;
    bool self_collision;
    bool quit{false};
    uint8_t length {2};

    SDL_Event e;
    snakeRenderer * renderer;
    snakeInput input;
    controller playerController;

    uint8_t MaxFps {60};
    int32_t previousTime {0};
    int32_t currentTime {0};
    int32_t lastLogic {0};
    float logicFPS {1.5f};
    uint32_t *windowSizeX, *windowSizeY;

    std::vector<genericObj> snake_components;
    genericObj fruit {0,0};
    std::vector<snakeText> text;

};
}
