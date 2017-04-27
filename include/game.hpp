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
#include <queue>
#include "objects/player.hpp"
#include "state.hpp"
#include "utils/Timer.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BUFF_SZ = 65536;
const int FRAMES_PER_SECOND = 12;

class Game {
protected:
    int height;
    int width;
    std::string name;
    std::vector<Player_base *> players;
    std::vector<Object *> objects;
    std::vector<std::pair<SDL_Keycode, Event>> controls;
    State_base state;

public:
    Game(std::string title, std::string title_screen_filename, \
            int screen_width=SCREEN_WIDTH, int screen_height=SCREEN_HEIGHT);

    void add_control(std::string func,
                     std::map<std::string, Event> &str_func_map,
                     std::map<std::string, std::pair
                     <SDL_Keycode, Event>> &str_key_func_map);

    void enqueue_event(Event e) {
        state.enqueue_event(e);
    }

    void update() {
        if(state.pending()) {
            state.dequeue_event();
        }
        for(auto obj : objects) {
            obj->update();
        }
    }
    void add_player(Player_base &player);
    void remove_player(Player_base *player);
    bool collision(Object &obj);
    std::map<std::string, std::pair<SDL_Keycode, Event>>
    parse_config(
            std::string config_file,
            std::map<std::string, Event> func_map);
    void handle_keypress(SDL_Keycode key);
    int run();
    virtual void update_screen() = 0;
};



#endif /* __GAME_HPP__ */

