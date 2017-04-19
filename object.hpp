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
        sprite.set_source_pos(x, y);
        sprite.set_height_width(h, w);
    }

    void set_position(int x, int y) {
        std::cerr << "object set_position" << std::endl;
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
    int get_height() { return size.w; };
    int get_width() { return size.h; };
    int get_x() { return pos.x; };
    int get_y() { return pos.y; };
    void set_x(int i) { pos.x = i; };
    void set_y(int i) { pos.y = i; };
    void set_sprite(SDL_Renderer *renderer, std::string filename) {
        std::cerr << "object set sprite" << std::endl; 
        sprite.set_sprite(renderer, filename);
        sprite.set_height_width(size.h, size.w);
        sprite.src.x = sprite.src.y = 0;
        sprite.set_position(pos.x, pos.y);
    }
};

#endif /* __OBJECT_HPP__ */


