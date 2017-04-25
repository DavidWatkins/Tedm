/**
  event.cpp
Purpose: Define event for game object to subscribe/respond to 
*/

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "player.hpp"
#include "state.hpp"
#include "environment.hpp"
#include <map>
#include <vector>

Class Event {
    Game game;
    vector<std::string, Player_base&> players;
    vector<std::string, Object> objects;
    std::function<void()> action;
public:
    Event(Game g, vector<Player_base&> p, vector<Object&> o, std::function f) {
        game = g;
        players = p;
        objects = o;
        action = f;
    }
    run() {
        action();
    }
}

#endif /* __EVENT_HPP__ */

