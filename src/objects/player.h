/**
    player.hpp
    Purpose: define user-controlled player or enemy/npc
*/

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include "objects/object.h"

namespace Tedm {
    class Player_base : public Tedm::Object {
    public:
        Player_base(Graphics &g, const int x, const int y, const int h, const int w) :
                Object(g, x,y,h,w) {
        };

        Player_base(Graphics &g, std::string filename, const int x, const int y, const int h, const int w) :
                Object(g, filename, x,y,h,w) {
        };
    };
}

#endif /* __PLAYER_HPP__ */

