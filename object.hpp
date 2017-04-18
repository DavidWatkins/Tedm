/**
    object.hpp
    most basic game object. All game elements should inherit object
*/

#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <iostream>
#include "sprite.hpp"

class Object {
protected:
    struct{
        int x, y, z;
    } pos;
    struct {
        int w, h, d;
    } size;
public:
    Sprite_base sprite;
    Object(const int x, const int y, const int h, const int w) {
        pos.x = x;
        pos.y = y;
        size.h = h;
        size.w = w;
    }

    void set_position(int x, int y) {
        sprite.set_position(x, y);
    }

    bool collision(Object &obj) {
        if(obj.pos.x < pos.x + size.w &&
           obj.pos.x + obj.size.w > pos.x &&
           obj.pos.y < pos.y + size.h &&
           obj.size.h + obj.pos.y > pos.y) {
            return true;
        }
        return false;
    }
};

#endif /* __OBJECT_HPP__ */



