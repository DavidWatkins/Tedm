#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "graphics.hpp"

Graphics::Graphics(){}

Graphics::Graphics(int height, int width, std::string title) {
    init(height, width, title);
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window);
    SDL_Quit();
}

Graphics& Graphics::operator=(const Graphics& rhs) {
    window = rhs.window;
    renderer = rhs.renderer;
    texture = rhs.texture;
    return *this;
}

bool Graphics::init(int height, int width, std::string title) {
    const int imgFlags = IMG_INIT_PNG|IMG_INIT_JPG;
    SDL_Window *window = NULL;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        std::cerr << "Warning: Linear texture filtering not enabled!" << std::endl;
    }

    //Create window
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, \
            SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", \
                SDL_GetError());
        return false;
    }

    //Get window surface
    if( !( IMG_Init( imgFlags  ) & imgFlags  )  )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n",
                IMG_GetError() );
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    //Fill the surface white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Update the surface
    SDL_RenderClear( renderer );

    //*w = window;
    return true;
}

SDL_Texture *Graphics::loadTexture(SDL_Renderer *renderer, std::string path) {
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

    return newTexture;
}

SDL_Surface *Graphics::loadIMG(SDL_PixelFormat *format, std::string filename) {
    SDL_Surface* optimizedSurface = NULL;

    std::cerr << "Loading: " << filename << std::endl;
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

void Graphics::add_background(std::string filename) {
    texture = loadTexture(renderer, filename);
    SDL_RenderCopy(renderer, texture, NULL, NULL );
    SDL_RenderPresent( renderer );
    //return texture;
}

void Graphics::draw(std::vector<Object *> objects) {
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    for(Object *o : objects) {
        SDL_Rect *rc = o->sprite.get_pos();
        SDL_Texture *sprite = o->sprite.get_sprite();
        SDL_RenderCopy(renderer, sprite, &o->sprite.src, &o->sprite.tgt);
    }
    SDL_RenderPresent(renderer);
}

