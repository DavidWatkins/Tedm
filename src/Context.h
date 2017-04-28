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
 * @file Context.h
 * @author David Watkins, Theodore Ahlfeld, and Matthew Haigh
 * @date 27 April 2017
 * @brief Contains details about the game condition
 */

#ifndef TEDM_CONTEXT_H
#define TEDM_CONTEXT_H

#include <string>

namespace Tedm {
    /**
     * @brief Contains details about the game condition
     */
    class Context {
    public:
        int width;
        int height;
        std::string windowTitle;
        bool isRunning;
        int timeSinceLastLoop;
        long targetFramerate;
        bool isPaused;
        
        /**
         * @brief Constructor sets the default starting conditions with 
         * default screen size
         */
        Context() : timeSinceLastLoop{0}, isRunning{false},
                    targetFramerate{10}, isPaused{false},
                    width{800}, height{600} {
        }

        /**
         * @brief Constructor sets the default starting conditions with 
         * user-defined screen size
         * @param w Screen width
         * @param h Screen height
         */
        Context(int w, int h) : timeSinceLastLoop{0}, isRunning{false},
                                targetFramerate{10}, isPaused{false},
                                width{w}, height{h} {
        }
    };
}

#endif //TEDM_CONTEXT_H
