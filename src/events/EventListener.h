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
 *  @file    EventListener.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Define functions to occur upon event occurance.
 *  User can overload () operator and it will be executed with the event
 *
 */

#ifndef TEDM_EVENTLISTENER_H
#define TEDM_EVENTLISTENER_H

#include <SDL2/SDL_keycode.h>

namespace Tedm {
    /**
    *  @brief Define functions to occur upon event occurance.
    *  User can overload () operator and it will be executed with the event
    *  This is the default case for custom events that are not SDL key events.
    */
    class EventListener {
    public:
        virtual void operator()() = 0;
    };

    /**
    *  @brief Define functions to occur upon event occurance.
    *  User can overload () operator and it will be executed with the event
    *  This is executed upon keypress.
    */
    class KeyEventListener {
    public:
        virtual void operator()(SDL_Keycode sym) = 0;
    };

    /**
    *  @brief Define functions to occur upon event occurance.
    *  User can overload () operator and it will be executed with the event
    *  This is executed upon mouse movement.
    */
    class MouseMoveListener {
    public:
        virtual void operator()(int x, int y, int rel_x, int rel_y,
                                bool left_click, bool right_click, bool middle_click) = 0;
    };

    /**
    *  @brief Define functions to occur upon event occurance.
    *  User can overload () operator and it will be executed with the event
    *  This is executed upon mouse wheel interaction.
    */
    class MouseWheelListener {
    public:
        virtual void operator()(bool scroll_up, bool scroll_down) = 0;
    };

    /**
    *  @brief Define functions to occur upon event occurance.
    *  User can overload () operator and it will be executed with the event
    *  This is executed upon mouse button press.
    */
    class MouseButtonListener {
    public:
        virtual void operator()(int x, int y) = 0;
    };

    /**
    *  @brief Define functions to occur upon event occurance.
    *  User can overload () operator and it will be executed with the event
    */
    class UserListener {
    public:
        virtual void operator()(int type, int code, void* data1, void* data2) = 0;
    };
}

#endif //TEDM_EVENTLISTENER_H
