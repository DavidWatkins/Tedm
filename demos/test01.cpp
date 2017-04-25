/**
    test01.hpp
    working test file for anything
    currently SDL graphics
*/

/*
link to SDL tutorial
www.lazyfoo.net/tutorials/SDL/index.php
*/

#include "game.hpp"

int main(int argc, char **argv) {
    SDL_Surface *surface;
    SDL_Window *w;
    Graphics::init(&w, &surface, 600, 800, "test01");
    Graphics::add_background(w, surface, 600, 800, "resources/dat_anakin.jpg");
    char c;
    std::cin >> c;
}
