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
#include <string>

class Graphics_SDL {
    SDL_Window *window;
    SDL_Rendereer *renderer;
    SDL_Texture *texture;
public:
    Graphics(int height, int width, std::string title);
    ~Graphics();
    static const std::string RELOAD_BACKGROUND;
    static bool init(SDL_Window **window, SDL_Renderer **renderer, \
        /*SDL_Surface *screen, */int height, int width, std::string title);
    static SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);
    static SDL_Surface *loadIMG(SDL_PixelFormat *format, std::string filename);
    static void update_screen(SDL_Renderer *renderer, SDL_Texture *texture, \
            SDL_Rect &src, SDL_Rect &dst);
    static SDL_Texture *add_background(std::string filename);
};

#endif /* __GRAPHICS_HPP__ */
