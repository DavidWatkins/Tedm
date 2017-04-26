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
    graphics = Graphics(screen_height, screen_width, title);
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
        std::map<std::string, Event>&str_func_map,
        std::map<std::string, std::pair
        <SDL_Keycode, Event>> &str_key_func_map){
    std::pair<SDL_Keycode, Event> key_func_pair = str_key_func_map.find(func)->second;
    controls.push_back(std::make_pair(key_func_pair.first, key_func_pair.second));
}

std::map<std::string, std::pair<SDL_Keycode, Event>>
Game::parse_config(std::string config_file,
        std::map<std::string, Event> func_map) {

    std::ifstream infile(config_file);
    //std::map<std::string, SDL_Keycode> keymap;
    std::map<std::string, std::pair<SDL_Keycode, Event>> controls;
    while(infile) {
        std::string line;
        if (!getline(infile, line)) break;
        std::istringstream ss(line);
        std::string func, button;
        std::getline(ss, func, ':' );
        std::getline(ss, button);
        std::cout << "(" << button << ", " << func << ")" << std::endl;
        //keymap.insert(std::make_pair(func, SDL_GetKeyFromName(button.c_str())));
        controls.insert(std::make_pair(func, std::make_pair(
                        SDL_GetKeyFromName(button.c_str()),
                        func_map.find(func)->second)));
    }
    return controls;
}

void Game::handle_keypress(SDL_Keycode key) {
    for(auto it : controls) {
        if(key==it.first) {
            enqueue_event(it.second);
            return;
        }
    }
}

int Game::run() {
    update_screen();
    SDL_Event e;
    Timer fps;
    bool quit = false;
    //char ch;
    while( !quit ) {

        //start frame timer
        fps.start();

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 ) {

                //User requests quit
                if( e.type == SDL_QUIT ) {
                    quit = true;
                } else if( e.type == SDL_KEYDOWN ) { //User presses a key
                    handle_keypress(e.key.keysym.sym);
                }
                //process a pending event for each object
                for (Object *o : objects) {
                    if (o->state.pending()) {
                        o->state.dequeue_event();
                    } 
                }
            }

        update();
        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
        update_screen();
    }
    return 0;
}

void Game::update_screen() {
    graphics.draw(objects);
}

