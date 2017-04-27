//
// Created by david on 4/27/17.
//

#include "Game.h"

Tedm::Game::Game() {
    ctx.width = 800;
    ctx.height = 600;
//    ctx.bpp = 32;
//    ctx.videoModeFlags = (SDL_HWSURFACE | SDL_DOUBLEBUF);
    ctx.windowTitle = "";
}

Tedm::Game::Game(Tedm::Context ctx) {

}

Tedm::Game::~Game() {

}

void Tedm::Game::start() {

}

void Tedm::Game::setTargetFramerate() {

}

void Tedm::Game::setWindowTitle() {

}

void Tedm::Game::setEventHandler() {''

}

void Tedm::Game::shutdown() {

}

void Tedm::Game::registerState(std::string id, Tedm::State s) {

}

bool Tedm::Game::init() {
    return false;
}

void Tedm::Game::destroy() {

}

void Tedm::Game::pause() {

}

void Tedm::Game::resume() {

}
