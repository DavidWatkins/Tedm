//
// Created by david on 4/27/17.
//

#include "State.h"

Tedm::State::State(Game &game, std::string id) :
        game(game), graphics(game.graphics), id(id), eventHandler(game.eventHandler), context(game.context) {}