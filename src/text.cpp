#include "text.hpp"

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <iostream>

namespace snake {

snakeText::snakeText(SDL_Renderer * p_renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color)
{
    textTexture = loadFont(p_renderer, font_path, font_size, message_text, color);
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
}

void snakeText::display(uint8_t x, uint8_t y, SDL_Renderer * p_renderer)
{
    textRect.x = x;
    textRect.y = y;

    SDL_RenderCopy(p_renderer, textTexture, nullptr, &textRect);
}


SDL_Texture * snakeText::loadFont(SDL_Renderer * p_renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color)
{
    TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
    if (!font)
        std::cerr << "failed to load font\n";

    SDL_Surface * textSurface = TTF_RenderText_Solid(font, message_text.c_str(), color);
    if (!textSurface)
        std::cerr << "failed to create text surface\n";
    
    SDL_Texture * textTexture = SDL_CreateTextureFromSurface(p_renderer, textSurface);
    if (!textTexture)
        std::cerr << "failed to create text texture\n";

    SDL_FreeSurface(textSurface);
    return textTexture;

    
}
}