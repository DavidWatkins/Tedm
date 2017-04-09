#include "game.hpp"
#include "event.hpp"
#include "state.hpp"
#include "player.hpp"

class Player : public Player_base {
    size.h = 20;
    size.w = 5;


public:
    Player(const int x, const int y) :pos.x{x},pos.y{y} {}
    void set_sprite(std::string filename) {
        sprite = Sprite_base(filename);
    }
    const SDL_Surface *get_sprite() const {
        sprite->rc.x = pos.x;
        sprite->rc.y = pos.y;
        sprite->rc.w = size.w;
        sprite->rc.h = size.h;
        return sprite.get_sprite();
    }
}

int main(int argc, char*argv[]) {

}
