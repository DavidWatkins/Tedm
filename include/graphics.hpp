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
#include <vector>
#include "object.hpp"

class Graphics {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
public:
    Graphics();
    Graphics(int height, int width, std::string title);
    ~Graphics();
    Graphics& operator=(const Graphics& rhs);
    const std::string RELOAD_BACKGROUND;
    bool init(int height, int width, std::string title);
    SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);
    SDL_Surface *loadIMG(SDL_PixelFormat *format, std::string filename);
    void update_screen(SDL_Renderer *renderer, SDL_Texture *texture, \
            SDL_Rect &src, SDL_Rect &dst);
    void add_background(std::string filename);
    void draw(std::vector<Object *> objects);
};

#endif /* __GRAPHICS_HPP__ */
