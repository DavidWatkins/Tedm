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
    const SDL_Surface *get_sprite() const {
        return sprite.get_sprite();
    }
};

int main(int argc, char*argv[]) {
    Game game(int, int, "resources/dat_anakin.jpg");
    char ch;
    std::cin >> ch;
}
