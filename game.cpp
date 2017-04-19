#include <algorithm>
#include "game.hpp"

//map controls for config file
std::map<std::string, SDL_Keycode> keymap = {{"up", SDLK_UP}, \
    {"down", SDLK_DOWN}, {"w", SDLK_w}, {"s", SDLK_s}};

Game::Game(std::string title, std::string title_screen_filename, \
        int screen_width, int screen_height, std::string config_file)
: height{screen_height},width{screen_width} {
    if (config_file != "None") {
        if (parse_config(config_file) == false) {
            std::cerr << "Configuration file invalid" << std::endl;
        }
    }
}

void Game::add_player(Player_base &player) {
    if (config.HasMember("controls")) {
        if (config["controls"].HasMember(player.name.c_str())) {
            for (auto itr = config["controls"][player.name.c_str()].MemberBegin(); \
                    itr != config["controls"][player.name.c_str()].MemberEnd(); \
                    ++itr) {
                std::string func = itr->name.GetString();
                std::string button= itr->value.GetString();
                SDL_Keycode key = keymap.find(button)->second;
                std::function<void(Player_base&)> f = player.functions.find(func)->second;
                player.controls.insert(std::pair<SDL_Keycode, std::function<void(Player_base&)>>(key, f));
            }
        }
    }
    objects.push_back(&player);
    players.push_back(&player);
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
