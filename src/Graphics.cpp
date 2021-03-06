/****************************************************************************
 *                                                                          *
 * This file is part of Tedm.                                               *
 *                                                                          *
 *   Tedm is free software: you can redistribute it and/or modify it        *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Box is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Tedm.  If not, see <http://www.gnu.org/licenses/>.  *
 ****************************************************************************/

/**
 * @file Graphics.cpp
 * @author David Watkins, Theodore Ahlfeld, and Matthew Haigh
 * @date 27 April 2017
 * @brief The user should be able to choose a graphics solution, so this class
 * abstracts graphics away from the game library. The graphics object is passed
 * to objects that will require rendering. It currently represents SDL and 
 * contains window and renderer objects.
 * @see www.lazyfoo.net/tutorials/SDL/index.php
 */

#include "Graphics.h"

bool Tedm::Graphics::init(int height, int width, std::string name) {
    const int imgFlags = IMG_INIT_PNG|IMG_INIT_JPG;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        //TODO REPLACE WITH LOGGER
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        //TODO REPLACE WITH LOGGER
        std::cerr << "Warning: Linear texture filtering not enabled!" << std::endl;
    }

    //Create window
    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, \
            SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        //TODO REPLACE WITH LOGGER
        printf("Window could not be created! SDL_Error: %s\n", \
                SDL_GetError());
        return false;
    }

    //Get window surface
    if( !( IMG_Init( imgFlags  ) & imgFlags  )  )
    {
        //TODO REPLACE WITH LOGGER
        printf( "SDL_image could not initialize! SDL_image Error: %s\n",
                IMG_GetError() );
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    //Fill the surface white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Update the surface
    SDL_RenderClear( renderer );

    initialized = true;

    return true;
}

SDL_Texture *Tedm::Graphics::loadTexture(std::string path) const {
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ) {
        //TODO REPLACE WITH LOGGER
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if( newTexture == NULL ) {
            //TODO REPLACE WITH LOGGER
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

SDL_Surface *Tedm::Graphics::loadIMG(SDL_PixelFormat *format, std::string filename) const {
    SDL_Surface* optimizedSurface = NULL;

    //TODO REPLACE WITH LOGGER
    std::cerr << "Loading: " << filename << std::endl;
    SDL_Surface* loadedSurface = IMG_Load( filename.c_str() );
    if( loadedSurface == NULL ) {
        //TODO REPLACE WITH LOGGER
        printf( "Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError() );
    } else {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, format, 0);
        if( optimizedSurface == NULL )
        {
            //TODO REPLACE WITH LOGGER
            printf( "Unable to optimize image %s! SDL Error: %s\n", filename.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

SDL_Texture *Tedm::Graphics::add_background(std::string filename) const {
    SDL_Texture *texture {loadTexture(filename)};
    SDL_RenderCopy(renderer, texture, NULL, NULL );
    SDL_RenderPresent( renderer );
    return texture;
}

bool Tedm::Graphics::isInitialized() {
    return initialized;
}

void Tedm::Graphics::setWindowTitle(std::string windowTitle) {
    SDL_SetWindowTitle(window, windowTitle.c_str());
}

void Tedm::Graphics::destroy() {
    //Destroy window
    SDL_DestroyWindow( window );
}

Tedm::Graphics::~Graphics() {
    //Destroy window
    if(window)
        SDL_DestroyWindow( window );
}

void Tedm::Graphics::draw(SDL_Texture *texture) const {
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void Tedm::Graphics::draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *tgt)
    const {
    SDL_RenderCopy(renderer, texture, src, tgt);
}

void Tedm::Graphics::present() const {
    SDL_RenderPresent(renderer);
}
