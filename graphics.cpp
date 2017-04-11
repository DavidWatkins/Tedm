#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "graphics.hpp"

bool Graphics::init(SDL_Window *window, SDL_Surface *screenSurface, \
        int height, int width, std::string name) {
    const int imgFlags = IMG_INIT_PNG|IMG_INIT_JPG;
    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    //Create window
    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, \
            SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", \
                SDL_GetError());
        return false;
    }
    else {
        //Get window surface
        if( !( IMG_Init( imgFlags  ) & imgFlags  )  )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n",
                    IMG_GetError() );
            return false;
        }
        screenSurface = SDL_GetWindowSurface( window );

        //Fill the surface white
        SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, \
                    0xFF, 0xFF, 0xFF ) );

        //Update the surface
        SDL_UpdateWindowSurface( window );
    }
    return true;
}

SDL_Surface *Graphics::loadIMG(SDL_PixelFormat *format, std::string filename) {
    SDL_Surface* optimizedSurface = NULL;

    SDL_Surface* loadedSurface = IMG_Load( filename.c_str() );
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError() );
    } else {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, format, 0);
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", filename.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

bool Graphics::add_background(SDL_Window *window, SDL_Surface *screenSurface, \
        int height, int width, std::string filename) {
    SDL_Surface* optimizedSurface = loadIMG(screenSurface->format, filename);

    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.h = height;
    stretchRect.w = width;

    SDL_BlitScaled(optimizedSurface, 0, screenSurface, &stretchRect);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(optimizedSurface);
    return true;
}

void Graphics::update_screen(SDL_Window *w, SDL_Surface *sprite,
                                    SDL_Surface *screen, SDL_Rect &rc) {
    SDL_BlitSurface(sprite, NULL, screen, &rc);
    SDL_UpdateWindowSurface(w);
}
