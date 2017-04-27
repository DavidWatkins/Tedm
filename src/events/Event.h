/**
 *  @file    Event.h
 *  @author  David Watkins
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief FIX ME
 *
 *  @section DESCRIPTION
 *
 *   FIX ME
 *
 */

#ifndef TEDM_EVENT_H
#define TEDM_EVENT_H

#include <SDL_events.h>

namespace Tedm {
    class Event {
    public:
        /**
         *
         * @param e
         */
        Event(SDL_Event e) : e(e) {}

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

        getNewWindowWidth
                int getNewWindowHeight() { return e.resize.h; }

    private:
        SDL_Event e;
    };
}

#endif //TEDM_EVENT_H
