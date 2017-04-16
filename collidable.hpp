/**
    collidable.hpp
    Purpose: Defines what it means to be collidable
*/

#ifndef __COLLIDABLE_HPP__
#define __COLLIDABLE_HPP__

#include "sprite.hpp"

class Collidable {
protected:
    struct{
        int x, y, z;
    } pos;
    struct {
        int w, h, d;
    } size;
public:
    Sprite_base sprite;
    Collidable(const int x, const int y, const int h, const int w) {
        pos.x = x;
        pos.y = y;
        size.h = h;
        size.w = w;
    }

    void set_position(int x, int y) {
        sprite.set_position(x, y);
    }

    bool collision(Collidable &obj) {
        if(obj.pos.x < pos.x + size.w &&
           obj.pos.x + obj.size.w > pos.x &&
           obj.pos.y < pos.y + size.h &&
           obj.size.h + obj.pos.y > pos.y) {
            return true;
        }
        return false;
    }


};

#endif /* __COLLIDABLE_HPP__ */



