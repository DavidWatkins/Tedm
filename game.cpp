#include <algorithm>
#include "game.hpp"

Game::Game(std::string title, std::string title_screen_filename, \
        int screen_width, int screen_height) {
    SDL_Rect stretchRect;
    Graphics::init(window, screenSurface, screen_height, screen_width, name);
    Graphics::add_background(window, screenSurface, screen_height, screen_width, \
            title_screen_filename);
}

void Game::add_player(Player_base &player) {
    Player_base *p = new Player_base(player);
    players.push_back(p);
}

void Game::remove_player(Player_base *player) {
    auto it = find(players.begin(), players.end(), player);
    if(it==players.end()){
        std::cerr << "Error, could not remove player";
    }
    delete *it;
    players.erase(it);
}

Game::~Game() {
    auto it = players.end();
    while(!players.empty()) {
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
//    for(Player_base *p : players) {
//        /* draw the sprite */
//        SDL_BlitSurface(p->get_sprite, NULL, screen, &rcSprite);
//        /* update the screen */
//        SDL_UpdateRect(screen, 0, 0, 0, 0);
//    }
}
