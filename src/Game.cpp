//
// Created by david on 4/27/17.
//

#include <utils/Timer.h>
#include "Game.h"

Tedm::Game::Game() : ctx(Context()), currentState(graphics) {
    ctx.width = 800;
    ctx.height = 600;
//    ctx.bpp = 32;
//    ctx.videoModeFlags = (SDL_HWSURFACE | SDL_DOUBLEBUF);
    ctx.windowTitle = "";
    log.setLevel(Logger::Level::LOG_INFO);
}

Tedm::Game::Game(Tedm::Context ctx) : ctx(ctx), currentState(graphics)  {
}

Tedm::Game::~Game() {

}

void Tedm::Game::mainLoop() {
    if(state_id_dict.size() == 0) {
        log.log_error("No states in the state dictionary, aborting...");
        exit(-1);
    }

    if(!init()) {
        log.log_error("Initialization failure; aborting execution");
        exit(-1);
    } else if(!currentState.init()) {
        log.log_error("User initialization failure; aborting execution");
        destroy();
        exit(-1);
    }

    Event event;
    Timer fps;

    log.log_debug("Starting App execute loop");
    while(ctx.isRunning) {
        // pull time
        fps.start();

        // check events
        while(eventHandler.poll()) {
            eventHandler.process();
        }

        if(!ctx.isPaused) {
            // update the scene
            currentState.update();

            // render the scene
            currentState.render();

            if( fps.get_ticks() < 1000 / ctx.targetFramerate ) {
                SDL_Delay( ( 1000 / ctx.targetFramerate ) - fps.get_ticks() );
            }
        }
    }

    // done; destroy
    currentState.destroy();
    destroy();
}

void Tedm::Game::setTargetFramerate(int fps) {
    if(fps > 0 && fps <= 1000) {
        ctx.targetFramerate = (long) floor(1000.0 / fps);
        log.log_debug("New target frame duration: " + std::to_string(ctx.targetFramerate) + "ms");
    } else {
        log.log_error("Target framerate must be between 1 and 1000 (inclusive)");
    }
}

void Tedm::Game::setWindowTitle(std::string windowTitle) {
    ctx.windowTitle = windowTitle;
    graphics.setWindowTitle(ctx.windowTitle);
}

void Tedm::Game::setEventHandler(EventHandler &eventHandler) {
    log.log_info("Setting the event handler");
    this->eventHandler = eventHandler;
}

void Tedm::Game::shutdown() {
    ctx.isRunning = false;
}

void Tedm::Game::registerState(std::string id, Tedm::State s) {
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
    if(!graphics.init(ctx.width, ctx.height, ctx.windowTitle)) {
        log.log_error("Unable to initialize graphics");
        return false;
    }

    graphics.setWindowTitle(ctx.windowTitle);

    return true;
}

void Tedm::Game::destroy() {
    log.log_debug("Exiting game...");
    // standard cleanup
    graphics.destroy();
    SDL_Quit();
}

void Tedm::Game::pause() {
    ctx.isPaused = true;
    //TODO Add event on pause
}

void Tedm::Game::resume() {
    ctx.isPaused = false;
    //TODO add event on resume
}

bool Tedm::Game::collision(Object &obj) {
    for(auto &x : objects) {
        if(x.collision(obj)) return true;
    }
    return false;
}