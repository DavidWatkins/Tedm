/**
 *  @file    State.h
 *  @author  David Watkins
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief State object used for defining a game state
 *
 *  @section DESCRIPTION
 *
 *  This c++ class defines the basis for a given game. Each
 *  game should define a state through which it enters and
 *  subsequently exits from.
 *
 */

#ifndef TEDM_STATE_H
#define TEDM_STATE_H

namespace Tedm {
    class State;
}

#include <SDL2/SDL.h>
#include <string>
#include <events/EventHandler.h>

#include "Context.h"
#include "events/Event.h"
#include "Game.h"

namespace Tedm {
    class State {
    public:
        State(const Graphics &graphics, Game &game) :
                graphics(graphics), ctx(Context()), id(""), game(game) {}

        State(const Graphics &graphics, Game &game, Context &ctx,
              std::string id) : graphics(graphics), ctx(Context()), id(id),
                                game(game) {}

        virtual ~State() {};

        std::string getID() { return id; }

        virtual bool init() = 0;

        virtual void update() = 0; //Add time as parameter?

        virtual void render() = 0;

        virtual void destroy() = 0;

        virtual void paused() = 0;

        virtual void resumed() = 0;

        void setEventHandler(EventHandler &eventHandler) {
            this->eventHandler = &eventHandler;
        }

        bool operator==(const State &other) { return id == other.id; }

    protected:

        Game &game;
        Context ctx;
        const Graphics &graphics;
        EventHandler *eventHandler;
        std::string id;

    };
}

#endif //TEDM_STATE_H
