/**
  player.cpp
Purpose: define user-controlled player or enemy/npc
*/

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "state.hpp"
#include "event.hpp"
#include "sprite.hpp"
#include "object.hpp"

#include <map>
#include <vector>

class Player_base : public Object {
    public:
        std::map<std::string, std::function<void(Player_base&)>> functions;
        std::map<SDL_Keycode, std::function<void(Player_base&)>> controls;
        std::string name;
        std::vector<std::function<void(Player_base)>> control_funcs;
        Player_base(std::string nm, const int x, const int y, const int h, \
                const int w)
            : Object(x,y,h,w) {
                name = nm;
        };
};
#endif /* __PLAYER_HPP__ */

