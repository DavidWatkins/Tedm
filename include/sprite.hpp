#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite_base {
public:
    SDL_Texture *sprite;
    SDL_Rect src;
    SDL_Rect tgt;
    //Sprite_base() {}
    /* Sprite_base(SDL_Renderer *renderer, std::string filename, int height, \
            int width) {

        set_height_width(height, width);
        set_sprite(renderer, filename, height, width);
    } */

    Sprite_base(int x, int y, int h, int w, std::string image) {
        set_pos(x, y);
        set_height_width(h, w);
    } 

    ~Sprite_base() {
        if(sprite) {
            SDL_DestroyTexture(sprite);
        }
    }

    void set_sprite(SDL_Renderer *renderer, std::string path, int height, \
            int width, int x, int y) {
        //The final texture
        
        SDL_Texture* newTexture = NULL;

        //Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
        if( loadedSurface == NULL ) {
            printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        } else {
            //Create texture from surface pixels
            newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface );
            if( newTexture == NULL ) {
                printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            }

            //Get rid of old loaded surface
            SDL_FreeSurface( loadedSurface );
        }

        sprite =  newTexture;
        set_height_width(height, width);
        src.x = src.y = 0;
        set_position(x, y);
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

#endif
