#include <algorithm>
#include <sstream>
#include "state.hpp"
#include "environment.hpp"
#include "event.hpp"
#include "graphics.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include "game.hpp"

Game::Game(std::string title, std::string title_screen_filename, \
        int screen_width, int screen_height)
: height{screen_height},width{screen_width} {
}

void Game::add_player(Player_base &player) {
    objects.push_back(&player);
    players.push_back(&player);
}

void Game::remove_player(Player_base *player) {
    auto it = find(players.begin(), players.end(), player);
    if(it==players.end()){
        std::cerr << "Error, could not remove player";
    }
    delete *it;
    players.erase(it);
}

bool Game::collision(Object &obj) {
    for(auto *x : objects) {
        if(x->collision(obj)) return true;
    }
    return false;
}
void Game::add_control(std::string func,
                       std::map<std::string,std::function<void()>>&str_func_map,
                       std::map<std::string, std::pair
                       <SDL_Keycode, std::function<void()>>> &str_key_func_map){
    auto key_func_pair = str_key_func_map.find(func)->second;
    buttons.push_back(key_func_pair.first);
    functions.push_back(key_func_pair.second);
}

std::map<std::string, std::pair<SDL_Keycode, std::function<void()>>>
        Game::parse_config(std::string config_file,
            std::map<std::string, std::function<void()>> func_map) {

    std::ifstream infile(config_file);
    std::map<std::string, SDL_Keycode> keymap;
    std::map<std::string, std::pair<SDL_Keycode, std::function<void()>>> controls;
    while(infile) {
        std::string line;
        if (!getline(infile, line)) break;
        std::istringstream ss(line);
        std::string func, button;
        std::getline(ss, func, ':' );
        std::getline(ss, button);
        std::cout << "(" << button << ", " << func << ")" << std::endl;
        keymap.insert(std::make_pair(func, SDL_GetKeyFromName(button.c_str())));
        controls.insert(make_pair(func, make_pair(
                    SDL_GetKeyFromName(button.c_str()),
                    func_map.find(func)->second)));
    }
    return controls;
}

void Game::handle_keypress(SDL_Keycode key) {
    for(int i = 0; i < buttons.size(); i++) {
        if(key==buttons[i]) {
            (functions[i])();
            return;
        }
    }
}
