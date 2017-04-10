#include <algorithm>
#include "game.hpp"

Game::Game(int screen_width, int screen_height, \
        std::string title_screen_filename, std::string name) {
    SDL_Rect stretchRect;
    Graphics::init(window, screenSurface, screen_height, screen_width, name);
    Graphics::add_background(screenSurface, screen_height, screen_width, \
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
    //Destroy window
    SDL_DestroyWindow( window );
    //Quit SDL subsystems
    SDL_Quit();
}


void Game::update() {
    for(Player_base &p : players) {
        /* draw the sprite */
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
        /* update the screen */
        SDL_UpdateRect(screen, 0, 0, 0, 0);
    }
}
