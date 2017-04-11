#include <vector>
#include "game.hpp"
#include "event.hpp"
#include "state.hpp"
#include "player.hpp"
#include "sprite.hpp"

class Player : public Player_base {
public:
    static SDL_PixelFormat *format;
    //Player(const int x, const int y) :pos.x{x},pos.y{y},size.h{20},size.w{5} {}
    Player(const int x, const int y) {
        pos.x = x;
        pos.y = y;
        size.h = 20;
        size.w = 5;
    }

    Player(const int x, const int y, std::string filename) {
        pos.x = x;
        pos.y = y;
        size.h = 20;
        size.w = 5;
        set_sprite(filename);
    }

    void set_sprite(std::string filename) {
        sprite = Sprite_base(format, filename);
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
        int screen_width, int screen_height) :
        Game(title,title_screen_filename, screen_width, screen_height) {
            Player::format = screenSurface->format;
        }

    Player *add_player(Player p) {
    }

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
    Player p(15,300, "resources/blue.png");
    Player *p1 {game.add_player(p)};
    char ch;
    std::cout << "Game Loaded" << std::endl;
    game.update_screen();
    std::cin >> ch;
}
