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
 *  @file    Event.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Create hooks for key presses and other in-game events that
 *  trigger changes in game state
 *
 */

#ifndef TEDM_EVENT_H
#define TEDM_EVENT_H

#include <SDL2/SDL_events.h>

namespace Tedm {
    
    /**
     *  @brief Create hooks for key presses and other in-game events that
     *  trigger changes in game state
     */
    class Event {
    public:
        /**
         * @brief Constructor 
         * @param e the SDL_Event to hook
         */
        Event() : e(SDL_Event()) {}

        /**
         * @brief Retrieve the SDL_Event from the event object
         * @return The event
         */
        SDL_Event &getEvent() { return e; }

        /**
         * @brief Retrieve the type of SDL_Event
         * @return The event type
         */
        int getType() { return e.type; }

        /**
         * @brief Retrieve the keycode for the key event
         * @return The keycode for the key event
         */
        SDL_Keycode getKeySymbol() { return e.key.keysym.sym; }

        /**
         * @brief Retrieve the mouse x coordinate movement
         * @return The x coordinate movement distance
         */
        int getMouseX() { return e.motion.x; }

        /**
         * @brief Retrieve the mouse y coordinate movement
         * @return The y coordinate movement distance
         */
        int getMouseY() { return e.motion.y; }

        int getMouseXRel() { return e.motion.xrel; }

        int getMouseYRel() { return e.motion.yrel; }

        /**
         * @brief Retrieve the mouse left button press event
         * @return the movement data during the press event
         */
        bool leftButtonPress() { return (e.motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0; }

        /**
         * @brief Retrieve the mouse right button press event
         * @return the movement data during the press event
         */
        bool rightButtonPress() { return (e.motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0; }

        /**
         * @brief Retrieve the mouse middle button press event
         * @return the movement data during the press event
         */
        bool middleButtonPress() { return (e.motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0; }

        /**
         * @brief Retrieve the mouse button pressed
         * @return the button keycode of the button pressed
         */
        int currentMouseButtonPress() { return e.button.button; }

        /**
         * @brief Retrieve the mouse X button press event
         * @return the movement data during the press event
         */
        int currentMouseButtonX() { return e.button.x; }

        /**
         * @brief Retrieve the mouse Y button press event
         * @return the movement data during the press event
         */
        int currentMouseButtonY() { return e.button.y; }

        /**
         * @brief check if a SDL_Event has occurred such as a keypress or 
         * mouse event
         * @return True if an Event has occurred
         */
        bool poll() { return (bool) SDL_PollEvent(&e); }

    private:
        SDL_Event e;
    };
}

#endif //TEDM_EVENT_H
