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
#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON'
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BUFF_SZ = 65536;


class Game {
protected:
    int height;
    int width;
    std::string name;
    std::vector<Player_base *> players;
    std::vector<Object *> objects;
    rapidjson::Document config;

public:
    Game(std::string title, std::string title_screen_filename, \
            int screen_width=SCREEN_WIDTH, int screen_height=SCREEN_HEIGHT,\
            std::string config_file="None");
    Game(Game&& G) :height{G.height}, name{G.name},
                    width{G.width} {}
    ~Game();
    void update();

    void enqueue_event() {

    }
    //Event_base *dequeue_event() {

    //}
    void add_player(Player_base &player);
    void remove_player(Player_base *player);
    bool collision(Object &obj);
    bool parse_config(std::string config_file);
    void handle_keypress(SDL_Keycode key);
};



#endif /* __GAME_HPP__ */

