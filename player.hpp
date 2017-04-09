/**
    player.cpp
    Purpose: define user-controlled player or enemy/npc
*/

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "state.hpp"
#include "event.hpp"

class Player_base {
    struct pos{
        int x, y, z;
    }
    struct size{
        int w, h, d;
    }
    Sprite_base sprite;
}


#endif /* __PLAYER_HPP__ */

