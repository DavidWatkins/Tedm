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

    private:
        SDL_Event e;
    };
}

#endif //TEDM_EVENT_H
