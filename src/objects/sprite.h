#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <string>
#include <SDL2/SDL.h>
#include "Graphics.h"

namespace Tedm {

    class Sprite_base {
    public:
        SDL_Texture *sprite;
        SDL_Rect src;
        SDL_Rect tgt;
        Tedm::Graphics *graphics;
        Sprite_base() {}

        Sprite_base(Tedm::Graphics &g, std::string filename, int height, int width) : graphics{&g} {
            set_height_width(height, width);
            set_sprite(filename);
        }

        ~Sprite_base() {
            if(sprite) {
                SDL_DestroyTexture(sprite);
            }
        }

        void set_sprite(std::string filename) {
            sprite = graphics->loadTexture(filename);
        }

        void set_height_width(int height, int width) {
            src.w = tgt.w = width;
            src.h = tgt.h = height;
        }

        SDL_Texture *get_sprite() {
            return sprite;
        }

        void set_source_pos(int x, int y) {
            //location of the sprite within the texture
            src.x = x;
            src.y = y;
        }

        void set_position(int x, int y) {
            tgt.x = x;
            tgt.y = y;
        }

        SDL_Rect *get_pos() {
            return &tgt;
        }

        SDL_Rect *get_src() {
            return &src;
        }
    };
};

#endif
