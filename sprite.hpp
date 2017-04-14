#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <string>
#include <SDL2/SDL.h>
#include "graphics.hpp"

class Sprite_base {
    SDL_Texture *sprite;
public:
    SDL_Rect rc;
    Sprite_base() {}
    Sprite_base(SDL_Renderer *renderer, std::string filename) {
        sprite = Graphics::loadTexture(renderer, filename);
    }
    ~Sprite_base() {
        if(sprite) {
        }
    }
    SDL_Texture *get_sprite() {
        return sprite;
    }
};

#endif
