/**
    graphics.hpp
    purpose: abstract away SDL and give users our own graphics api
    built into game objext
*/

/*
link to sdl tutorial
www.lazyfoo.net/tutorials/SDL/index.php
*/

#ifndef __GRAPHICS_HPP__
#define __GRAPHICS_HPP__

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Graphics {
    //The window we'll be rendering to'
    SDL_Window *window;
    //The surface contained by the window
    SDL_Surface *screenSurface;
public:
    Graphics(int width=SCREEN_WIDTH, int height=SCREEN_HEIGHT);
    ~Graphics();
    bool init();
    bool add_background(std::string fname);
    void destroy();
};

#endif /* __GRAPHICS_HPP__ */
