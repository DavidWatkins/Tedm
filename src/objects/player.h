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
 *  @brief Define player object for game interaction
 *  The developer can inherit player to create custom players for each game
 *
 */

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include "objects/object.h"

namespace Tedm {
    /**
    *  @brief Define player object for game interaction
    *  The developer can inherit player to create custom players for each game
    */
    class Player_base : public Tedm::Object {
    public:
        /**
         * @brief Constructor creates object to represent player
         * @see Object
         */
        Player_base(Graphics &g, const int x, const int y, const int h, const int w) :
                Object(g, x,y,h,w) {
        };

        /**
         * @brief Constructor creates object to represent player
         * Includes default image
         * @see Object
         */
        Player_base(Graphics &g, std::string filename, const int x, const int y, const int h, const int w) :
                Object(g, filename, x,y,h,w) {
        };
    };
}

#endif /* __PLAYER_HPP__ */

