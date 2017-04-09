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


class Graphics {
public:
    Graphics(int width=SCREEN_WIDTH, int height=SCREEN_HEIGHT);
    ~Graphics();
    static bool init();
    static bool add_background(SDL_Surface *screenSurface,
                               SDL_Rect &stretchRect,
                               std::string filename);
    static SDL_Surface *loadIMG(std::string filename);
    void destroy();
};

#endif /* __GRAPHICS_HPP__ */
