/**
    object.hpp
    most basic game object. All game elements should inherit object
*/

#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include "sprite.h"
#include "../../old/state.hpp"
#include <iostream>

class Object {
protected:
    struct{
        int x, y, z;
    } pos;
    struct {
        int w, h, d;
    } size;
public:
    State_base state;
    Sprite_base sprite;

    Object() {
        pos.x = 0;
        pos.y = 0;
        size.h = 0;
        size.w = 0;
        sprite.set_source_pos(0, 0);
        sprite.set_height_width(0, 0);
    }

    Object(const int x, const int y, const int h, const int w) {
        pos.x = x;
        pos.y = y;
        size.h = h;
        size.w = w;
        sprite.set_source_pos(x, y);
        sprite.set_height_width(h, w);
    }

    void set_position(int x, int y) {
        sprite.set_position(x, y);
    }

    bool collision(Object &obj) {
        return obj.pos.x < pos.x + size.w &&
       obj.pos.x + obj.size.w > pos.x &&
       obj.pos.y < pos.y + size.h &&
       obj.size.h + obj.pos.y > pos.y;
    }

    int get_height() { return size.w; };
    int get_width() { return size.h; };
    int get_x() { return pos.x; };
    int get_y() { return pos.y; };
    void set_x(int i) { pos.x = i; };
    void set_y(int i) { pos.y = i; };
    void set_sprite(std::string filename) {
        sprite.set_sprite(renderer, filename);
        sprite.set_height_width(size.h, size.w);
        sprite.src.x = sprite.src.y = 0;
        sprite.set_position(pos.x, pos.y);
    }

    void update() {
        if(state.pending()) {
            state.dequeue_event();
        } else {
            //default action
        }
    }
};

#endif /* __OBJECT_HPP__ */



