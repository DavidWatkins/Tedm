/**
  player.cpp
Purpose: define user-controlled player or enemy/npc
*/

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "state.hpp"
#include "event.hpp"
#include "sprite.hpp"
#include "collidable.hpp"

class Player_base : public Collidable {
    public:
       // Sprite_base sprite;
//        Player_base() {}
        Player_base(const int x, const int y, const int h, const int w)
            : Collidable(x,y,h,w) {
                pos.x = x;
                pos.y = y;
            }
};


#endif /* __PLAYER_HPP__ */

