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
 * @file Graphics.h
 * @author David Watkins, Theodore Ahlfeld, and Matthew Haigh
 * @date 27 April 2017
 * @brief The user should be able to choose a graphics solution, so this class
 * abstracts graphics away from the game library. The graphics object is passed
 * to objects that will require rendering. It currently represents SDL and 
 * contains window and renderer objects.
 * @see www.lazyfoo.net/tutorials/SDL/index.php
 */

#ifndef __GRAPHICS_HPP__
#define __GRAPHICS_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "utils/Logger.h"

namespace Tedm {
    class Graphics {

    public:
        /**
         * @brief Constructor waits for initialization
         */
        Graphics() : renderer(NULL), window(NULL), initialized(false), l(Logger()) {}
        
        /**
         * @brief Default destructor
         */
        ~Graphics();

        /**
         * @brief Destroy resources
         */
        void destroy();

        /**
         * @brief Initialize graphics
         * @param height the screen height
         * @param width the screen width
         * @param the name for the screen window
         * @return true on success
         */
        bool init(int height, int width, std::string name);

        /**
         * @brief Load an image into a texture object. This is needed to render
         * a background or a sprite
         * @param path the file path
         * @return the new texture
         */
        SDL_Texture *loadTexture(std::string path) const;

        /**
         * @brief Load an image into an SDL_Surface object.
         * @param format the file format
         * @param filename the file path
         * @return the new surface
         */
        SDL_Surface *loadIMG(SDL_PixelFormat *format, std::string filename) const;

        /**
         * @brief define the current background 
         * @param filename the file path
         */
        SDL_Texture *add_background(std::string filename) const;

        /**
         * @brief Check if graphics are initialized
         * @return true if graphics are initialized
         */
        bool isInitialized();
        
        /**
         * @brief Set the title of the game window
         * @param basic_string the title
         */
        void setWindowTitle(std::string basic_string);

        /**
         * @brief draw a texture onto the screen
         * @param texture the item to draw
         */
        void draw(SDL_Texture *texture) const;

        /**
         * @brief draw a sprite onto the screen
         * @brief texture the sprite image
         * @brief src the location of the image in the sprite
         * @brief tgt the location on the screen
         */
        void draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *tgt) const;

        /**
         * @brief render the screen
         */
        void present() const;

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
        bool initialized;
        Logger l;
    };
}

#endif /* __GRAPHICS_HPP__ */
