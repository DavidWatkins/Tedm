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
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "utils/Logger.h"

namespace Tedm {
    class Graphics {

    public:
        Graphics() : renderer(NULL), window(NULL), initialized(false), l(Logger()) {}
        ~Graphics();

        void destroy();

        bool init(int height, int width, std::string name);
        SDL_Texture *loadTexture(std::string path) const;
        SDL_Surface *loadIMG(SDL_PixelFormat *format, std::string filename) const;
        void update_screen(SDL_Texture *texture, SDL_Rect &src, SDL_Rect &dst);
        SDL_Texture *add_background(std::string filename) const;

        bool isInitialized();

        void setWindowTitle(std::string basic_string);

        void draw(SDL_Texture *texture);
        void draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *tgt);

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
        bool initialized;
        Logger l;
    };
}

#endif /* __GRAPHICS_HPP__ */
