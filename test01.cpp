/**
    test01.hpp
    working test file for anything
    currently SDL graphics
*/

/*
link to SDL tutorial 
http://www.lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/cli/index.php 
*/

#include "game.hpp"

int main(int argc, char **argv) {
    //The window we'll be rendering to'
    SDL_Window *window = nullptr;
    //The surface contained by the window
    SDL_Surface *screenSurface = nullptr;
    
    //Initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
}
