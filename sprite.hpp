#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.hpp"

class Sprite_base {
public:
    SDL_Texture *sprite;
    SDL_Rect src;
    SDL_Rect tgt;
    Sprite_base() {}
    Sprite_base(SDL_Renderer *renderer, std::string filename, int height, \
            int width) {


        std::cerr << "BEFORE src: (" << src.h << ", " << src.w << ")" << std::endl;
        std::cerr << "BEFORE dst: (" << tgt.h << ", " << tgt.w << ")" << std::endl;
        set_height_width(height, width);
        std::cerr << "AFTER src: (" << src.h << ", " << src.w << ")" << std::endl;
        std::cerr << "AFTER dst: (" << tgt.h << ", " << tgt.w << ")" << std::endl;
        set_sprite(renderer, filename);
       /*
        //The final texture
        SDL_Texture* newTexture = NULL;

        //Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load( filename.c_str() );

        if( loadedSurface == NULL ) {
            printf( "Unable to load image %s! SDL_image Error: %s\n", \
                    filename.c_str(), IMG_GetError() );
        }

        else {

            //Create texture from surface pixels
            sprite = SDL_CreateTextureFromSurface( renderer, loadedSurface );

            if( sprite == NULL ) {
                printf( "Unable to create texture from %s! SDL Error: %s\n", \
                        filename.c_str(), SDL_GetError() );
            }
            else {
                //Get rid of old loaded surface
                SDL_FreeSurface( loadedSurface );
            }
        }*/

    }
    ~Sprite_base() {
        if(sprite) {
            //SDL_FreeSurface(sprite);
        }
    }

    void set_sprite(SDL_Renderer *renderer, std::string filename) {
        sprite = Graphics::loadTexture(renderer, filename);
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
};

#endif
