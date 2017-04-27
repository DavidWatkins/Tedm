/**
    player.hpp
    Purpose: define user-controlled player or enemy/npc
*/

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include "objects/object.hpp"

class Player_base : public Object {
public:
    Player_base(std::string nm, const int x, const int y, const int h, \
            const int w)
        : Object(x,y,h,w) {
    };
};
#endif /* __PLAYER_HPP__ */

