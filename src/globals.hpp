#pragma once

#include <SDL2/SDL.h>

#include <cstdint>
#include <string>


namespace snake{
class snakeGlobals{
public:
    std::string getWindowName() {return windowName; }

    uint32_t * getWindowSizeX() {return &windowSizeX;}
    uint32_t * getWindowSizeY() {return &windowSizeY;}

    uint8_t * getGameSizeX() {return &gameSizeX;}
    uint8_t * getGameSizeY() {return &gameSizeY;}

private:
    const std::string windowName = "Snake";
    uint32_t windowSizeX {400};
    uint32_t windowSizeY {400};
    
    uint32_t displayFrameRate {60};

    uint8_t gameSizeX {20};
    uint8_t gameSizeY {20};

    #if 0
    static SDL_Color snakeColor {};
    static SDL_Color bgColor {};
    static SDL_Color fruitColor {};

    bool mobile {false};
    #endif
};
}