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
 * @file Game.h
 * @author David Watkins, Theodore Ahlfeld, and Matthew Haigh
 * @date 27 April 2017
 * @brief Primary object in library. The game contains all other members which
 * together represent a game. Developers can inherit this class to define 
 * a game.
 */

#ifndef TEDM_GAME_H
#define TEDM_GAME_H

namespace Tedm {
    class Game;
}

#include <unordered_map>
#include "events/EventHandler.h"
#include "utils/Logger.h"
#include "objects/object.h"
#include "Context.h"
#include "State.h"
#include "Graphics.h"
#include "utils/Timer.h"

namespace Tedm {
    /**
     * @brief Primary object in library. The game contains all other members which
     * together represent a game. Developers can inherit this class to define 
     * a game.
     */
    class Game {
        friend class State;
    public:
        /**
         * @brief Constructor creates a game, with context and state, at default 
         * screen size
         */
        Game();

        /**
         * @brief Constructor creates a game, with context and state
         */
        Game(Context ctx);

        /**
         * @brief Default destructor
         */
        virtual ~Game();

        /**
         * @brief main game function. Maintains frame rate and executes virtual 
         * update() function in child class. Checks for events and user input.
         */
        void mainLoop();

        /**
         * @brief Sets the target frame rate
         * @param fps the desired rate
         */
        void setTargetFramerate(int framerate);

        /**
         * @brief Sets the title of the game window
         * @param windowTitle the new title
         */
        void setWindowTitle(std::string windowTitle);

        /**
         * @brief Ends the game
         */
        void shutdown();

        /*
         * @brief Adds a state to the game
         * @param id The string identifier of the state
         * @param s A pointer to the state
         */
        void registerState(std::string id, std::shared_ptr<State> s);

        /**
         * @brief Transition to a new state
         * @param newStateId the string identifier of the new state
         */
        void transition(std::string newStateId);
    protected:

        /**
         * @brief initialize the game. Initialize graphics
         */
        virtual bool init();

        /**
         * @brief Destroy and clean up the game
         */
        virtual void destroy();

        /**
         * @brief Pause execution
         */
        virtual void pause();

        /**
         * @brief End pause condition
         */
        virtual void resume();

        EventHandler eventHandler;
        Graphics graphics;

        Context context;
        std::unordered_map<std::string, std::shared_ptr<State>> state_id_dict;
        std::string currentStateId;
        std::string startStateId;

        Logger log;

        std::string nextStateId;
        bool doTransition;
    };

}

#endif //TEDM_GAME_H
