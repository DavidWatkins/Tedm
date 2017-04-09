#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <string>

class Sprite_base {
    SDL_Surface *sprite;
public:
    SDL_Rect rc;
    Sprite_base(std::string filename) {
        SDL_Surface *temp = Graphics::loadIMG(filename);
        sprite = SDL_DisplayFormat(temp);
        SDL_FreeSurface(temp);
    }
    ~Sprite_base() {
        if(sprite) {
            SDL_FreeSurface(sprite);
        }
    }
    const SDL_Surface *get_sprite() const {
        return sprite;
    }
}

#endif
