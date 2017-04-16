#include <vector>
#include "game.hpp"
#include "event.hpp"
#include "state.hpp"
#include "sprite.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

class Player : public Player_base {
    const unsigned int move_distance {10};
    const int HEIGHT = 100;
    const int WIDTH  = 10;
    public:

    /* Player() {
        size.h = HEIGHT;
        size.w = WIDTH;
    } */

    Player(const int x, const int y) : Player_base(x,y,100,10) {
        set_pos(x, y);
    }

    /*Player(const int x, const int y) {
        pos.x = x;
        pos.y = y;
        size.h = HEIGHT;
        size.w = WIDTH;
        //set_rc(x,y,100,10);
    }*/

    void set_pos(int x, int y){
        pos.x = x;
        pos.y = y;
        sprite.set_position(x, y);
    }


    void set_sprite(SDL_Renderer *renderer, std::string filename /*, int src_x, \
            int src_y, int tgt_x, int tgt_y*/) {
        sprite.set_sprite(renderer, filename);
        sprite.set_height_width(size.h, size.w);
        sprite.src.x = sprite.src.y = 0;
    }

    void move_up() {
        pos.y -=move_distance;
        if(pos.y < 0) {
            pos.y = 0;
        }
        sprite.set_position(pos.x, pos.y);
    }

    void move_down() {
        pos.y +=move_distance;
        if(pos.y > 500) {
            pos.y = 500;
        }
        sprite.set_position(pos.x, pos.y);
    }
};

class Ball : public Collidable {
    public:
    Ball(int posx, int posy, int srcx, int srcy) : Collidable(posx,posy,10,50) {
        sprite.set_height_width(10, 50);
        sprite.set_source_pos(srcx, srcy);
        sprite.set_position(posx, posy);
    }

    void set_sprite(SDL_Renderer *renderer, string filename) {
        std::cout << "BALL: (" << sprite.src.x << ", " << sprite.src.y << ", " << sprite.src.h << ", " << sprite.src.w << ")" << std::endl;
        std::cout << "BALL: (" << sprite.tgt.x << ", " << sprite.tgt.y << ", " << sprite.tgt.h << ", " << sprite.tgt.w << ")" << std::endl;

        sprite.set_sprite(renderer, filename);
        std::cout << "BALL: (" << sprite.src.x << ", " << sprite.src.y << ", " << sprite.src.h << ", " << sprite.src.w << ")" << std::endl;
        std::cout << "BALL: (" << sprite.tgt.x << ", " << sprite.tgt.y << ", " << sprite.tgt.h << ", " << sprite.tgt.w << ")" << std::endl;
    }
};

class Pong : public Game {
private:
    std::vector<Player *> players;
    std::vector<Sprite_base *> sprites;
    SDL_Texture *background;
    SDL_Renderer *renderer;
    SDL_Window *window;
    Player p1, p2;
    Ball ball;

public:

    enum EVENTS {P1_MOVE_UP, P1_MOVE_DOWN, P2_MOVE_UP, P2_MOVE_DOWN, GAME_END};
    Pong(std::string title, std::string title_screen_filename, \
         int screen_width, int screen_height) :
         Game(title,title_screen_filename, screen_width, screen_height),
         p1{Player(15,250)}, p2{Player(750,250)} ,ball{Ball(375,295, 0, 0)} {

        Graphics::init(&window, &renderer, screen_height, screen_width, title);
        background = Graphics::add_background(renderer, title_screen_filename);

        add_player(&p1);
        add_player(&p2);
        ball.set_sprite(renderer, "resources/blaster.png");
        collidables.push_back(&ball);
        sprites.push_back(&ball.sprite);
    }

    void add_player(Player *p) {
        p->set_sprite(renderer, "resources/blue1.png");
        players.push_back(p);
        collidables.push_back(p);
        sprites.push_back(&p->sprite);
    }

    void enqueue_events(EVENTS e) {
        switch(e) {
            case P1_MOVE_UP:
                p1.move_up();
                break;
            case P1_MOVE_DOWN:
                p1.move_down();
                break;
            case P2_MOVE_UP:
                p2.move_up();
                break;
            case P2_MOVE_DOWN:
                p2.move_down();
                break;
        }
    }

    void new_round() {
        p1.set_pos(15,250);
        p2.set_pos(750, 250);
    }

    void update_screen() {
        for(auto sprt : sprites) {
            SDL_Rect *rc = sprt->get_pos();
            SDL_Texture *sprite = sprt->get_sprite();
            SDL_Rect bg_redraw;
            bg_redraw.x = rc->x-10;
            bg_redraw.y = rc->y-10;
            bg_redraw.h = rc->h+20;
            bg_redraw.w = rc->w+20;

            Graphics::update_screen(renderer, sprite, sprt->src, sprt->tgt);
        }
    }
};

int main(int argc, char*argv[]) {
    Pong game = Pong("pong", "resources/dat_anakin.jpg", 800, 600);
    bool quit = false;
    char ch;
    std::cout << "Game Loaded" << std::endl;
    game.update_screen();
    SDL_Event e;
    while( !quit ) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            if( e.type == SDL_QUIT ) {
                quit = true;
            } else if( e.type == SDL_KEYDOWN ) { //User presses a key
                //Select surfaces based on key press
                switch( e.key.keysym.sym ) {
                    case SDLK_w:
                        game.enqueue_events(Pong::EVENTS::P1_MOVE_UP);
                    break;
                    case SDLK_s:
                        game.enqueue_events(Pong::EVENTS::P1_MOVE_DOWN);
                    break;
                    case SDLK_UP:
                        game.enqueue_events(Pong::EVENTS::P2_MOVE_UP);
                    break;
                    case SDLK_DOWN:
                        game.enqueue_events(Pong::EVENTS::P2_MOVE_DOWN);
                    break;
                }
                game.update_screen();
            }
        }
    }
}
