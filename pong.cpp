#include <vector>
#include "game.hpp"
#include "event.hpp"
#include "state.hpp"
#include "player.hpp"

class Player : public Player_base {

public:
    //Player(const int x, const int y) :pos.x{x},pos.y{y},size.h{20},size.w{5} {}
    Player(const int x, const int y) {
        pos.x = x;
        pos.y = y;
        size.h = 20;
        size.w = 5;
    }

    void set_sprite(std::string filename) {
        sprite = Sprite_base(filename);
    }
    SDL_Surface *get_sprite() {
        return sprite.get_sprite();
    }
    SDL_Rect get_rc() {
        SDL_Rect rc;
        rc.x = pos.x;
        rc.y = pos.y;
        rc.h = size.h;
        rc.w = size.w;
        return rc;
    }
};

class Pong : public Game {
private:
    std::vector<Player *> players;

public:
    Pong(std::string title, std::string title_screen_filename, \
        int screen_width, int screen_height) : Game(title,title_screen_filename, screen_width, screen_height) {}
    void update_screen() {
        for(Player *p : players) {
            SDL_Rect rc = p->get_rc();
            SDL_Surface *sprite = p->get_sprite();
            Graphics::update_screen(window, sprite, screenSurface, rc);
        }
    }
};

int main(int argc, char*argv[]) {
    Pong game = Pong("pong", "resources/dat_anakin.jpg", 800, 600);
    char ch;
    std::cin >> ch;
}
