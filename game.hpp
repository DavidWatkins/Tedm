/**
    game.cpp
    Purpose: Main class: game object represents entire game
*/

#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "player.hpp"
#include "state.hpp"
#include "environment.hpp"
#include "event.hpp"
#include "graphics.hpp"

#include <vector>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Game {
    //The window we'll be rendering to'
    SDL_Window *window;
    //The surface contained by the window
    SDL_Surface *screenSurface;
    int imgFlags = IMG_INIT_PNG|IMG_INIT_JPG;

    std::vector<Player_base *> players;
public:
    Game(std::string title_screen_filename);
    ~Game();
    void update();
    void add_player();
    void remove_player();
}



#endif /* __GAME_HPP__ */

