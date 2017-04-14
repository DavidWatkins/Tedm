/**
    player.cpp
    Purpose: define user-controlled player or enemy/npc
*/

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "state.hpp"
#include "event.hpp"
#include "sprite.hpp"

class Player_base {
protected:
    struct{
        int x, y, z;
    } pos;
    struct {
        int w, h, d;
    } size;
public:
    Sprite_base sprite;
    Player_base() {}
    Player_base(const int x, const int y) {
    pos.x = x;
    pos.y = y;
    }
};


#endif /* __PLAYER_HPP__ */

