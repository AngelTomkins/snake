#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// std
#include <string>

namespace snake{
class snakeText{
public:
    snakeText() {}
    snakeText(SDL_Renderer * p_renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);

    void display(uint8_t x, uint8_t y, SDL_Renderer * p_renderer);

    static SDL_Texture * loadFont(SDL_Renderer * p_renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);

private:
    SDL_Texture * textTexture = nullptr;
    SDL_Rect textRect;

};
}