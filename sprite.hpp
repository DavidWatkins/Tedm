#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <string>
#include <SDL2/SDL.h>
#include "graphics.hpp"

class Sprite_base {
    SDL_Surface *sprite;
    SDL_PixelFormat *format;
public:
    SDL_Rect rc;
    Sprite_base(SDL_PixelFormat *pformat, std::string filename) {
        format = pformat;
        sprite = Graphics::loadIMG(format, filename);
        //sprite = SDL_ConvertSurfaceFormat(temp, format, 0);
        //SDL_FreeSurface(temp);
    }
    ~Sprite_base() {
        if(sprite) {
            SDL_FreeSurface(sprite);
        }
    }
    const SDL_Surface *get_sprite() const {
        return sprite;
    }
};

#endif
