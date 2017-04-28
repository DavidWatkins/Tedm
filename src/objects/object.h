/****************************************************************************
 *                                                                          *
 * This file is part of Tedm.                                               *
 *                                                                          *
 *   Tedm is free software: you can redistribute it and/or modify it        *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Box is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Tedm.  If not, see <http://www.gnu.org/licenses/>.  *
 ****************************************************************************/

/**
 *  @file    player.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Basic game element. Any item in game should inherit object
 *
 */

#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <iostream>
#include "sprite.h"

namespace Tedm {
    /**
    *  @brief Basic game element. Any item in game should inherit object
    */
    class Object {
    protected:
        /**
         * @brief the position of the object on the scree
         */
        struct{
            int x, y, z;
        } pos;
        /**
         * @brief The size dimensions of the object
         */
        struct {
            int w, h, d;
        } size;
    public:

        Sprite_base sprite;

        /**
         * @brief Constructor sets default position to (0,0), default image
         * location in sprite to (0,0), and default size to (0,0)
         * @param g the Graphics object for the game
         */
        Object(Graphics &g) : sprite(g) {
            pos.x = 0;
            pos.y = 0;
            size.h = 0;
            size.w = 0;
            sprite.set_source_pos(0, 0);
            sprite.set_height_width(0, 0);
        }

        /**
         * @brief Constructor sets default position to (0,0), default image
         * location in sprite to (0,0), and default size to (0,0)
         * Includes filename to set image for sprite
         * @param g the Graphics object for the game
         * @param filename the file path for the image
         */
        Object(Graphics &g, std::string filename) : sprite(g, filename, 0, 0) {
            pos.x = 0;
            pos.y = 0;
            size.h = 0;
            size.w = 0;
            sprite.set_source_pos(0, 0);
            sprite.set_height_width(0, 0);
        }

        /**
         * @brief Constructor with position and size
         * @param g the Graphics object for the game
         * @param x the x coordinate screen location
         * @param y the y coordinate screen location
         * @param h the object height
         * @param w the object width
         */
        Object(Graphics &g, const int x, const int y, const int h, const int w) : sprite(g, h, w) {
            pos.x = x;
            pos.y = y;
            size.h = h;
            size.w = w;
            sprite.set_source_pos(x, y);
            sprite.set_height_width(h, w);
        }

        /**
         * @brief Constructor with position and size
         * Includes filename to set image for sprite
         * @param g the Graphics object for the game
         * @param x the x coordinate screen location
         * @param y the y coordinate screen location
         * @param h the object height
         * @param w the object width
         * @param filename the file path for the image
         */
        Object(Graphics &g, std::string filename, const int x, const int y, const int h, const int w) : sprite(g, filename, h, w) {
            pos.x = x;
            pos.y = y;
            size.h = h;
            size.w = w;
            sprite.set_source_pos(x, y);
            sprite.set_height_width(h, w);
        }
        
        /**
         * @brief set position of the sprite on the screen
         * @param x the x coordinate
         * @param y the y coordinate
         */
        void set_position(int x, int y) {
            sprite.set_position(x, y);
        }

        /**
         * @brief check if a collision has occured with another object
         * @param obj the object to check for collision
         * @return true if collision has occurred
         */
        bool collision(Object &obj) {
            return obj.pos.x < pos.x + size.w &&
                   obj.pos.x + obj.size.w > pos.x &&
                   obj.pos.y < pos.y + size.h &&
                   obj.size.h + obj.pos.y > pos.y;
        }

        /**
         * @brief Retrieve the height
         * @return the object height
         */
        int get_height() { return size.h; };
        
        /**
         * @brief Retrieve the width
         * @return the object width
         */
        int get_width() { return size.w; };

        /**
         * @brief Retrieve the x coordinate position
         * @return the x coordinate position
         */
        int get_x() { return pos.x; };
        
        /**
         * @brief Retrieve the y coordinate position
         * @return the y coordinate position
         */
        int get_y() { return pos.y; };
        
        /**
         * @brief Set the x coordinate position
         * @param i the new x coordinate position
         */
        void set_x(int i) { pos.x = i; };
        
        /**
         * @brief Set the y coordinate position
         * @param i the new y coordinate position
         */
        void set_y(int i) { pos.y = i; };

        /**
         * @brief Set the sprite image
         * @param filename the path to the new image
         */
        void set_sprite(std::string filename) {
            sprite.set_sprite(filename);
            sprite.set_height_width(size.h, size.w);
            sprite.src.x = sprite.src.y = 0;
            sprite.set_position(pos.x, pos.y);
        }
        
        /**
         * @brief render the sprite on the screen
         */
        void draw() {
            sprite.draw();
        }
    };
}

#endif /* __OBJECT_HPP__ */



