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
    int screen_height;
    int screen_width;
    //The window we'll be rendering to'
    SDL_Window *window;
    //The surface contained by the window
    SDL_Surface *screenSurface;
    std::string name;
    std::vector<Player_base *> players;
public:
    Game(std::string title_screen_filename, int screen_width=SCREEN_WIDTH, \
            int screen_height=SCREEN_HEIGHT);
    ~Game();
    void update();
    void add_player();
    void remove_player();
};



#endif /* __GAME_HPP__ */

