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
 *  @file    State.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
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
        /**
         * @brief Constructor
         * @param game the game parent
         * @param id the string identifier of the state
         */
        State(Game &game, std::string id);

        /**
         * @brief Default destructor
         */
        virtual ~State() {};

        /**
         * @brief Retrieve the string identifier
         * @return the string
         */
        std::string getID() { return id; }

        /**
         * @brief virtual function to be overridden by game-specific state
         * Contains logic executed at game start
         */
        virtual bool init() = 0;

        /**
         * @brief virtual function to be overridden by game-specific state
         * Contains logic executed at each frame
         */
        virtual void update() = 0; //Add time as parameter?

        /**
         * @brief virtual function to be overridden by game-specific state
         * Draws the state-appropriate items to the screen
         */
        virtual void render() = 0;

        /**
         * @brief virtual function to be overridden by game-specific state
         * Cleans state listeners in preperation for new state
         */
        virtual void destroy() = 0;

        /**
         * @brief virtual function to be overridden by game-specific state
         * Pauses the game
         */
        virtual void paused() = 0;

        /**
         * @brief virtual function to be overridden by game-specific state
         * Un-pauses the game
         */
        virtual void resumed() = 0;

        /**
         * @brief Copy assignment
         */
        bool operator==(const State &other) { return id == other.id; }

    protected:

        Game &game;
        Graphics &graphics;
        EventHandler &eventHandler;
        Context &context;
        std::string id;

    };
}

#endif //TEDM_STATE_H
