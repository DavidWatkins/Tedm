#include <vector>
#include "game.hpp"
#include "event.hpp"
#include "state.hpp"
#include "player.hpp"
#include "sprite.hpp"

class Player : public Player_base {
    const int HEIGHT = 50;
    const int WIDTH  = 10;
public:

    Player() {
        size.h = HEIGHT;
        size.w = WIDTH;
    }

    Player(const int x, const int y) {
        pos.x = x;
        pos.y = y;
        size.h = HEIGHT;
        size.w = WIDTH;
    }

    void set_pos(int x, int y){
        pos.x = x;
        pos.y = y;
    }


    void set_sprite(SDL_Renderer *renderer, std::string filename) {
        sprite = Sprite_base(renderer, filename);
    }

    SDL_Texture *get_sprite() {
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
    SDL_Renderer *renderer;

public:
    Pong(std::string title, std::string title_screen_filename, \
        int screen_width, int screen_height) :
        Game(title,title_screen_filename, screen_width, screen_height) {
            Graphics::init(&window, &renderer, screen_height, screen_width, title);
            Graphics::add_background(renderer, title_screen_filename);
        }

    Player *add_player(std::string sprite_fname) {
        Player *p = new Player();
        p->set_sprite(renderer, sprite_fname);
        players.push_back(p);
        return p;
    }

    void update_screen() {
        for(Player *p : players) {
            SDL_Rect rc = p->get_rc();
            SDL_Texture *sprite = p->get_sprite();
            Graphics::update_screen(renderer, sprite, rc);
        }
    }
};

int main(int argc, char*argv[]) {
    Pong game = Pong("pong", "resources/dat_anakin.jpg", 800, 600);
    Player *p1 {game.add_player("resources/blue.png")};
    p1->set_pos(15,200);
    char ch;
    std::cout << "Game Loaded" << std::endl;
    game.update_screen();
    std::cin >> ch;
}
