#include <vector>
#include <math.h>
#include "game.hpp"
#include "event.hpp"
#include "state.hpp"
#include "sprite.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

class Player : public Player_base {
    const static unsigned int move_distance {40};
    const int HEIGHT = 100;
    const int WIDTH  = 10;
    public:

    Player(std::string name, const int x, const int y) : \
        Player_base(name,x,y,100,10) {
        set_pos(x, y);
        functions["up"] = move_up;
        functions["down"] = move_down;
    }
    void set_pos(int x, int y){
        pos.x = x;
        pos.y = y;
        sprite.set_position(x, y);
    }

    void set_sprite(SDL_Renderer *renderer, std::string filename) {
        sprite.set_sprite(renderer, filename);
        sprite.set_height_width(size.h, size.w);
        sprite.src.x = sprite.src.y = 0;
    }

    std::function<void(Player_base&)> move_up() = [](Player_base &p) {
        p.set_y(p.get_y() - Player::move_distance);
        if(p.get_y() < 0) {
            p.set_y(0);
        }
        p.sprite.set_position(p.get_x(), p.get_y());
    }

    std::function<void(Player_base&)> move_down() = [](Player_base &p) {
        p.set_y(p_get_y() + Player::move_distance);
        if(p.get_y() > 500) {
            p.set_y()(500);
        }
        p.sprite.set_position(p.get_x(), p.get_y());
    }

    int get_y() {
        return Player_base.get_y;
    }

    int get_height() {
        return HEIGHT;
    }
};

class Ball : public Object {
    const double MAXBOUNCEANGLE {M_PI/12};
    double vx, vy;
    int start_x;
    int start_y;
    double ballSpeed;

public:
    Ball(int posx, int posy, int srcx, int srcy) : Object(posx,posy,10,50) {
        sprite.set_source_pos(srcx, srcy);
        sprite.set_height_width(10, 50);
        start_x = posx;
        start_y = posy;
        reset();
    }

    void reset() {
        pos.x = start_x;
        pos.y = start_y;
        vx = 1;
        vy = 0;
    }

    /* Snippet inspired by Ricket from
     * https://gamedev.stackexchange.com/questions/4253/in-pong-how-do-you-
     * calculate-the-balls-direction-when-it-bounces-off-the-paddl
     */
    void update_trajectory(Player *p) {
        int PADDLEHEIGHT = p->get_height();
        double relativeIntersectY = p->get_y()+(PADDLEHEIGHT/2) - (pos.y-(size.h/2));
        double normalizedRelativeIntersectionY = (relativeIntersectY/(PADDLEHEIGHT/2));
        double bounceAngle = normalizedRelativeIntersectionY * MAXBOUNCEANGLE;
        double ballSpeed = (sqrt((vx*vx) + (vy*vy)/25));
        int dir_x = (vx<0?1:-1);
        vx = ballSpeed*cos(bounceAngle)*dir_x;
        vy = ballSpeed*(-sin(bounceAngle)*5);
    }

    void update_trajectory() {
        vy=-vy;
    }

    void update_pos() {
        pos.y += round(vy);
        pos.x += round(vx);
        sprite.set_position(pos.x, pos.y);
    }

    void set_sprite(SDL_Renderer *renderer, string filename) {
        sprite.set_sprite(renderer, filename);
    }

    int get_x() {
        return pos.x;
    }

    int get_y() {
        return pos.y;
    }
};

class Pong : public Game {
private:
    std::vector<Object *> objects;
    SDL_Texture *background;
    SDL_Renderer *renderer;
    SDL_Window *window;
    Player p1, p2;
    Ball ball;

public:

    //enum EVENTS {P1_MOVE_UP, P1_MOVE_DOWN, P2_MOVE_UP, P2_MOVE_DOWN, RESET};
    Pong(std::string title, std::string title_screen_filename, \
         int screen_width, int screen_height, std::string config_file) :
         Game(title,title_screen_filename, screen_width, screen_height, \
                 config_file),
         p1{Player("player_1", 15,250)}, p2{Player("player_2",750,250)} \
             ,ball{Ball(375,295, 0, 0)} {

        Graphics::init(&window, &renderer, screen_height, screen_width, title);
        background = Graphics::add_background(renderer, title_screen_filename);

        add_player(&p1);
        add_player(&p2);
        ball.set_sprite(renderer, "resources/blaster.png");
        objects.push_back(&ball);
    }

    void add_player(Player *p) {
        p->set_sprite(renderer, "resources/blue1.png");
        objects.push_back(p);
    }

    /* void enqueue_events(EVENTS e) {
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
            case RESET:
                new_round();
                break;
        }
    } */

    void new_round() {
        p1.set_pos(15,250);
        p2.set_pos(750, 250);
        ball.reset();
    }

    void update_screen() {
        ball.update_pos();
        for(Object *o : objects) {
            if (o != &ball) {
                if(ball.collision(*o)) {
                    ball.update_trajectory(static_cast<Player *>(o));
                }
            }
        }
        if(ball.get_y() <= 0 || ball.get_y() >= height-10) {
            ball.update_trajectory();
        }
        if(ball.get_x() <= 0 || ball.get_x() >= width-50) {
            enqueue_events(RESET);
        }
        SDL_RenderCopy(renderer, background, NULL, NULL);
        for(auto o : objects) {
            SDL_Rect *rc = o->sprite.get_pos();
            SDL_Texture *sprite = o->sprite.get_sprite();
            SDL_RenderCopy(renderer, sprite, &o->sprite.src, &o->sprite.tgt);
        }
        SDL_RenderPresent(renderer);
    }
};

int main(int argc, char*argv[]) {
    Pong game = Pong("pong", "resources/dat_anakin.jpg", 800, 600, "pong.cfg");
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
                game.handle_keypress(e.key.keysym.sym);
                //Select surfaces based on key press
                /* switch( e.key.keysym.sym ) {
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
                } */
            }
        }
        game.update_screen();
    }
}
