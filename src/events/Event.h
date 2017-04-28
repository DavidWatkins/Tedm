/**
/****************************************************************************
 *                                                                          *
 * This file is part of Tedm.                                                *
 *                                                                          *
 *   Tedm is free software: you can redistribute it and/or modify it         *
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
 *   License along with Tedm.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

/**
 *  @file    Event.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief 
 *
 *  @section DESCRIPTION
 *
 *   FIX ME
 *
 */

#ifndef TEDM_EVENT_H
#define TEDM_EVENT_H

//#include <SDL_events.h>
#include <SDL2/SDL_events.h>

namespace Tedm {
    class Event {
    public:
        /**
         *
         * @param e
         */
        Event() : e(SDL_Event()) {}

        /**
         * Retrieve the SDL_Event from the event object
         *
         * @return
         */
        SDL_Event &getEvent() { return e; }

        int getType() { return e.type; }

        SDL_Keycode getKeySymbol() { return e.key.keysym.sym; }

        int getMouseX() { return e.motion.x; }

        int getMouseY() { return e.motion.y; }

        int getMouseXRel() { return e.motion.xrel; }

        int getMouseYRel() { return e.motion.yrel; }

        bool leftButtonPress() { return (e.motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0; }

        bool rightButtonPress() { return (e.motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0; }

        bool middleButtonPress() { return (e.motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0; }

        int currentMouseButtonPress() { return e.button.button; }

        int currentMouseButtonX() { return e.button.x; }

        int currentMouseButtonY() { return e.button.y; }

        bool poll() { return (bool) SDL_PollEvent(&e); }

    private:
        SDL_Event e;
    };
}

#endif //TEDM_EVENT_H
