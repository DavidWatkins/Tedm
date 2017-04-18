#include <algorithm>
#include "game.hpp"

Game::Game(std::string title, std::string title_screen_filename, \
        int screen_width, int screen_height, std::string config_file)
: height{screen_height},width{screen_width} {
    if (config_file != "None") {
        if (parse_config(config_file) == false) {
            std::cerr << "Configuration file invalid" << std::endl;
        }
    }
}

Player_base *Game::add_player(Player_base &player) {
    Player_base *p = new Player_base(player);
    if (config.HasMember("controls")) {
        if (config["controls"].HasMember(p->name.c_str())) {
            //auto ctls = config["controls"][p->name.c_str()];
            for (auto itr = config["controls"][p->name.c_str()].MemberBegin(); \
                    itr != config["controls"][p->name.c_str()].MemberEnd(); \
                    ++itr) {
                //button = itr->name.GetString();
                //func = itr->value.GetString();
                p->controls[keys[itr->name.GetString()]] = \
                    p->functions[itr->value.GetString()];
            }
        }
    }
    players.push_back(p);
    return p;
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
    //SDL_DestroyWindow( window );
    //Quit SDL subsystems
    SDL_Quit();
}

bool Game::collision(Object &obj) {
    for(auto *x : objects) {
        if(x->collision(obj)) return true;
    }
    return false;
}

void Game::update() {
    //check for collisions
    for (Object *o : objects) {
        for (Object *other : objects) {
            if (o != other) {
                o->collision(*other); 
            }
        }
    }
    //    for(Player_base *p : players) {
    //        /* draw the sprite */
    //        SDL_BlitSurface(p->get_sprite, NULL, screen, &rcSprite);
    //        /* update the screen */
    //        SDL_UpdateRect(screen, 0, 0, 0, 0);
    //    }
}

bool Game::parse_config(std::string config_file) {
    FILE *file = fopen(config_file.c_str(), "r");
    char buffer[BUFF_SZ];
    fread(buffer, 1, sizeof(buffer), file);
    rapidjson::StringStream s(buffer);
    if (config.ParseStream(s).HasParseError()) {
        return false;
    }
    return true;
}

void Game::handle_keypress(SDL_Keycode key) {
    for (Player_base *p : players) {
        if (p->controls.find(key) != p->controls.end()) {
            p->controls[key](*p);
        }
    }
}
