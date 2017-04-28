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
 * @file Game.cpp
 * @author David Watkins, Theodore Ahlfeld, and Matthew Haigh
 * @date 27 April 2017
 * @brief Primary object in library. The game contains all other members which
 * together represent a game. Developers can inherit this class to define 
 * a game.
 */

#include "Game.h"

Tedm::Game::Game() : context(Context()), startStateId("")  {
    context.width = 800;
    context.height = 600;
//    context.bpp = 32;
//    context.videoModeFlags = (SDL_HWSURFACE | SDL_DOUBLEBUF);
    context.windowTitle = "";
    log.setLevel(Logger::LogLevel::LOG_INFO);
    doTransition = false;
}

Tedm::Game::Game(Tedm::Context ctx) : context(ctx), startStateId("")  {
    doTransition = false;
    log.setLevel(Logger::LogLevel::LOG_INFO);
}

Tedm::Game::~Game() {

}

void Tedm::Game::mainLoop() {
    if(state_id_dict.size() == 0) {
        log.log_error("No states in the state dictionary, aborting...");
        exit(-1);
    }

    //TODO add check for startstate existing
    std::shared_ptr<State> currentState = state_id_dict[startStateId];

    if(!init()) {
        log.log_error("Initialization failure; aborting execution");
        exit(-1);
    } else if(!currentState->init()) {
        log.log_error("User initialization failure; aborting execution");
        destroy();
        exit(-1);
    }

    Timer fps;

    log.log_debug("Starting App execute loop");
    context.isRunning = true;
    while(context.isRunning) {
        //TODO Check that state exists
        if(doTransition) {
            log.log_info("Transitioning from " + currentStateId + " to " + nextStateId);
            std::shared_ptr<State> nextState = state_id_dict[nextStateId];
            currentState->destroy();
            if(!nextState->init()) {
                log.log_error("User initialization failure; aborting execution");
            }
            doTransition = false;
        }

        // pull time
        fps.start();

        // check events
        eventHandler.checkListeners();

        if(!context.isPaused) {
            // update the scene
            currentState->update();

            // render the scene
            currentState->render();
            //Flush graphics buffer to screen
            graphics.present();

            if( fps.get_ticks() < 1000 / context.targetFramerate ) {
                SDL_Delay( ( 1000 / context.targetFramerate ) - fps.get_ticks() );
            }
        }
    }

    // done; destroy
    currentState->destroy();
    destroy();
}

void Tedm::Game::setTargetFramerate(int fps) {
    if(fps > 0 && fps <= 1000) {
        context.targetFramerate = (long) floor(1000.0 / fps);
        log.log_debug("New target frame duration: " + std::to_string(context.targetFramerate) + "ms");
    } else {
        log.log_error("Target framerate must be between 1 and 1000 (inclusive)");
    }
}

void Tedm::Game::setWindowTitle(std::string windowTitle) {
    context.windowTitle = windowTitle;
    graphics.setWindowTitle(context.windowTitle);
}

void Tedm::Game::shutdown() {
    context.isRunning = false;
}

void Tedm::Game::registerState(std::string id, std::shared_ptr<Tedm::State> s) {
    state_id_dict.insert(std::make_pair(id, s));
}

bool Tedm::Game::init() {
    // safety check
    if(graphics.isInitialized()) {
        log.log_warning("Trying to reinitialize Game");
        return false;
    }

    log.log_debug("Game initializing...");

    // dump version info
    SDL_version v;
    SDL_VERSION(&v);

    // init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        log.log_error("SDL_Init failure: " + std::string(SDL_GetError()));
        return false;
    }

    // try to setup root surface
    if(!graphics.init(context.height, context.width, context.windowTitle)) {
        log.log_error("Unable to initialize graphics");
        return false;
    }

    graphics.setWindowTitle(context.windowTitle);

    return true;
}

void Tedm::Game::destroy() {
    log.log_debug("Exiting game...");
    // standard cleanup
    graphics.destroy();

    SDL_Quit();
}

void Tedm::Game::pause() {
    context.isPaused = true;
    //TODO Add event on pause
}

void Tedm::Game::resume() {
    context.isPaused = false;
    //TODO add event on resume
}

void Tedm::Game::transition(std::string newStateId) {
    nextStateId = newStateId;
    doTransition = true;
}

void Tedm::Game::setStartState(std::string startStateId) {
    this->startStateId = startStateId;
}
