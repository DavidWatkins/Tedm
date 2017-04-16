#ifndef __DRAWABLE_HPP__
#define __DRAWABLE_HPP__

#include <string>
#include <SDL2/SDL.h>
#include "sprite.hpp"
#include "graphics.hpp"

class Drawable {
protected:
    Sprite_base sprite;
    //SDL_Rect rc;
public:
    Drawable() {}
    Drawable(SDL_Renderer *renderer, std::string filename) {
        sprite = Sprite_base(renderer, filename, 0, 0, 0, 0);
    }
    ~Drawable() {
    }
    SDL_Texture *get_sprite() {
        return sprite.get_sprite();
    }
    /*void set_rc(int x, int y, int h, int w) {
        rc.h = h;
        rc.w = w;
        rc.x = x;
        rc.y = y;
    }

    SDL_Rect *get_rc() {
        return &rc;
    }
    */
};

#endif
