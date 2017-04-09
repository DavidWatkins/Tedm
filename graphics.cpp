#include <SDL2/SDL_image.h>
#include <string>
#include "graphics.hpp"

Graphics::Graphics(int width, int height) {
    window = nullptr;
    screenSurface = nullptr;
    this->init();
}

Graphics::~Graphics() {
    //Destroy window
    SDL_DestroyWindow( window );
    //Quit SDL subsystems
    SDL_Quit();
}

bool Graphics::init() {
    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    //Create window
    window = SDL_CreateWindow("Test01", SDL_WINDOWPOS_UNDEFINED, \
            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, \
            SDL_WINDOW_SHOWN);
    if(window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", \
                SDL_GetError());
        return false;
    }
    else {
        //Get window surface
        int imgFlags = IMG_INIT_PNG|IMG_INIT_JPG;
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

bool Graphics::add_background(std::string filename) {
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( filename.c_str() );
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError() );
    } else {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, screenSurface->format, 0);
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", filename.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;

    SDL_BlitScaled(optimizedSurface, 0, screenSurface, &stretchRect);
    SDL_UpdateWindowSurface(window);
    //SDL_FreeSurface(optimizedSurface);
    return true;
}


