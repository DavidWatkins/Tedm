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
 *  @file    sprite.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Graphic representation of game element
 *
 */

#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <string>
#include <SDL2/SDL.h>
#include <fstream>
#include "Graphics.h"

namespace Tedm {

    /**
     *  @brief Graphic representation of game element
     */
    class Sprite_base {
    public:
        SDL_Texture *sprite;
        SDL_Rect src;
        SDL_Rect tgt;
        std::string filename;
        Graphics &graphics;

        /**
         * @brief Constructor sets size to 0 and contains no image
         * @param g the game Graphics object
         */
        Sprite_base(Graphics &g) : graphics{g} {
            set_height_width(0, 0);
            this->filename = "";
            sprite = 0;
        }

        /**
         * @brief Constructor sets size without image
         * @param height the object height
         * @param width the object width
         * @param g the game Graphics object
         */
        Sprite_base(Graphics &g, int height, int width) : graphics{g} {
            set_height_width(height, width);
            this->filename = "";
            sprite = 0;
        }

        /**
         * @brief Constructor sets size and image
         * @param filename the image to load
         * @param height the object height
         * @param width the object width
         * @param g the game Graphics object
         */
        Sprite_base(Graphics &g, std::string filename, int height, int width) : graphics{g} {
            set_height_width(height, width);
            this->filename = filename;
            sprite = 0;
        }

        /**
         * @brief Destructor cleans up the texture
         */
        ~Sprite_base() {
            if(sprite) {
                SDL_DestroyTexture(sprite);
            }
        }

        /**
         * @brief Sets the sprite image
         * @param filename the image file path
         */
        void set_sprite(std::string filename) {
            std::ifstream f(filename.c_str());
            if(f.good())
                sprite = graphics.loadTexture(filename);
        }

        /**
         * @brief Set the size of the sprite
         * @param height the height
         * @param width the width
         */
        void set_height_width(int height, int width) {
            src.w = tgt.w = width;
            src.h = tgt.h = height;
        }

        /**
         * @brief Retrieve the underlying sprite object
         * @return the sprite texture
         */
        SDL_Texture *get_sprite() {
            return sprite;
        }

        /**
         * @brief set the location of the sprite within the image
         * @param x the x coordinate of the sprite in the image
         * @param y the y coordinate of the sprite in the image
         */
        void set_source_pos(int x, int y) {
            //location of the sprite within the texture
            src.x = x;
            src.y = y;
        }

        /** 
         * @brief set the position of the sprite on the screen
         * @param x the x coordinate location of the sprite on the screen
         * @param y the y coordinate location of the sprite on the screen
         */
        void set_position(int x, int y) {
            tgt.x = x;
            tgt.y = y;
        }

        /**
         * @brief Get the sprite location on the screen
         * @return the SDL_Rect object which contains location data
         */
        SDL_Rect *get_pos() {
            return &tgt;
        }

        /**
         * @brief Get the sprite location in the image
         * @return the SDL_Rect object which contains location data
         */
        SDL_Rect *get_src() {
            return &src;
        }

        /**
         * @brief Render the sprite on the screen
         */
        void draw() {
            if(!sprite)
                set_sprite(filename);

            if(sprite)
                graphics.draw(sprite, &src, &tgt);
        }
    };
};

#endif
