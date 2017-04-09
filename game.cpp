#include <algorithm>
#include "game.hpp"

Game::Game(std::string title_screen_filename) {
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT
    Graphics::add_background(screenSurface, stretchRect,
                             title_screen_filename);
}

void Game::add_player(Player_base &player) {
    Player_base *p = new Player_base(player);
    players.push_back(p);
}

void Game::remove_player(Player_base *player) {
    auto it = find(players.begin(), player.end(), player);
    if(it==players.end()){
        std::cerr << "Error, could not remove player";
    }
    delete *it;
    players.erase(it);
}

Game::~Game() {
    auto it = players.end();
    while(!player.empty()) {
        it--;
        delete *it;
        players.erase(it);
    }
}

void Game::update() {
    for(Player_base &p : players) {

    }
}
