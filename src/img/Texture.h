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
 *  @file    Texture.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Define Texture to store object or background image
 *
 */

#ifndef TEDM_TEXTURE_H
#define TEDM_TEXTURE_H

#include <SDL_system.h>

namespace Tedm {
    /**
    *  @brief Define Texture to store object or background image
    */
    class Texture {

    private:
        SDL_Texture *texture;
    };
}

#endif //TEDM_TEXTURE_H
