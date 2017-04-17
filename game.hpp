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
#include <queue>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Game {
protected:
    int height;
    int width;
    std::string name;
    std::vector<Player_base *> players;
    std::vector<Collidable *> collidables;

public:
    Game(std::string title, std::string title_screen_filename, \
            int screen_width=SCREEN_WIDTH, int screen_height=SCREEN_HEIGHT);
    Game(Game&& G) :height{G.height}, name{G.name},
                    width{G.width} {}
    ~Game();
    void update();

    void enqueue_event() {

    }
    //Event_base *dequeue_event() {

    //}
    Player_base *add_player(Player_base &player);
    void remove_player(Player_base *player);
    bool collision(Collidable &obj) {
        for(auto *x : collidables) {
            if(x->collision(obj)) return true;
        }
        return false;
    }
};



#endif /* __GAME_HPP__ */

