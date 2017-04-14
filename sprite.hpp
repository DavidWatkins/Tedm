#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.hpp"

class Sprite_base {
    //SDL_PixelFormat *format;
    public:
        SDL_Texture *sprite;
        SDL_Rect src;
        SDL_Rect tgt;
        Sprite_base() {}
        Sprite_base(SDL_Renderer *renderer, std::string filename, int height, \
                int width, int src_x, int src_y, int tgt_x, int tgt_y) {

            //location of the sprite within the texture
            src.x = src_x;
            src.y = src_y;
            src.w = width;
            src.h = height;

            //location to be placed on the screen
            tgt.x = tgt_x;
            tgt.y = tgt_y;
            tgt.w = width;
            tgt.h = height;

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
            }
        }
        ~Sprite_base() {
            if(sprite) {
                //SDL_FreeSurface(sprite);
            }
        }
        SDL_Texture *get_sprite() {
            return sprite;
        }

        bool set_position(int x, int y) {
            tgt.x = x;
            tgt.y = y;
        }
};

#endif
