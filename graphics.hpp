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
    Graphics();
public:
    static bool init(SDL_Window **window, SDL_Surface **surface, \
            int height, int width, std::string name);
    static bool add_background(SDL_Window *window, SDL_Surface *screenSurface, \
            int height, int width, std::string filename);
    static SDL_Surface *loadIMG(SDL_PixelFormat *format, std::string filename);
    static void update_screen(SDL_Window *w, SDL_Surface *sprite,
                              SDL_Surface *screen, SDL_Rect &rc);
};

#endif /* __GRAPHICS_HPP__ */
