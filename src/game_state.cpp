#include "game_state.hpp"

Game_state_base(std::string n, Environment &e) {
    name = n;
    environment = e;
}

std::string Game_state_base::get_name() {
    return name
}

Game_state() {
    
}

void Game_state::add_state(Game_state_base &state) {
    states.insert(std::make_pair(state.get_name(), state));
}
