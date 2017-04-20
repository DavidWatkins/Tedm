/**
    game.cpp
    Purpose: Main class: game object represents entire game
*/

#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SDL2/SDL.h>
#include <string.h>
#include <functional>
#include <map>
#include "player.hpp"

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
    std::vector<SDL_Keycode> buttons;
    std::vector<std::function<void()>> functions;

public:
    Game(std::string title, std::string title_screen_filename, \
            int screen_width=SCREEN_WIDTH, int screen_height=SCREEN_HEIGHT);
    void update();

    void enqueue_event() {

    }
    void add_player(Player_base &player);
    void remove_player(Player_base *player);
    bool collision(Object &obj);
    std::map<std::string, std::pair<SDL_Keycode, std::function<void()>>>
    parse_config(
            std::string config_file,
            std::map<std::string, std::function<void()>> func_map);
    void handle_keypress(SDL_Keycode key);
};



#endif /* __GAME_HPP__ */

