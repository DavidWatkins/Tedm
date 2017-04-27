//
// Created by David on 4/24/2017.
//

#include <vector>
#include <math.h>
#include "Game.h"
#include "objects/sprite.h"
#include "objects/player.h"
#include <iostream>

using namespace std;
using namespace Tedm;

class Player : public Player_base {
    const unsigned int move_distance = 40;
    const int HEIGHT = 100;
    const int WIDTH  = 10;
public:

    Player(const int x, const int y) : Player_base(x,y,100,10) {
        set_pos(x, y);
    }

    void set_pos(int x, int y){
        pos.x = x;
        pos.y = y;
        sprite.set_position(x, y);
    }

    void move_up() {
        set_y(get_y() - move_distance);
        if(get_y() < 0) {
            set_y(0);
        }
        sprite.set_position(get_x(), get_y());
    }

    void move_down() {
        set_y(get_y() + move_distance);
        if(get_y() > 500) {
            set_y(500);
        }
        sprite.set_position(get_x(), get_y());
    }

    int get_y() {
        return Object::get_y();
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
    void update_trajectory(Player &p) {
        int PADDLEHEIGHT = p.get_height();
        double relativeIntersectY = p.get_y()+(PADDLEHEIGHT/2) - (pos.y-(size.h/2));
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

    void set_sprite(string filename) {
        sprite.set_sprite(filename);
    }

    int get_x() {
        return pos.x;
    }

    int get_y() {
        return pos.y;
    }
};

class Player_KeyBoard_Listener : KeyEventListener {
    Player *p1, *p2;
public:
    Player_KeyBoard_Listener(Player &p1, Player &p2) {
        this->p1 = &p1;
        this->p2 = &p2;
    }
    void operator()(SDL_Keycode sym) override {
        switch(sym) {
            case SDLK_w:
                p1->move_up();
                break;
            case SDLK_s:
                p1->move_down();
                break;
            case SDLK_UP:
                p2->move_up();
                break;
            case SDLK_DOWN:
                p2->move_down();
                break;
        }
    }
};

class Pong_State : public State {
public:
    Player p1, p2;
    Ball ball;
    Player_KeyBoard_Listener pkl;
    Pong_State(const Graphics &graphics, Game &game) :
            State(graphics, game),p1{Player(15, 250)},
            p2{Player(750, 250)}, ball{Ball(375,295, 0, 0)},
            pkl{p1, p2};

    SDL_Texture *background;

    void new_round() {
        p1.set_pos(15,250);
        p2.set_pos(750, 250);
        ball.reset();
    }

    bool init() override {

        game.setWindowTitle("Dat Pong");
        background = graphics.add_background("resources/dat_anaking.jpg");
        game.eventHandler.OnKeyDown(
                make_shared<Player_KeyBoard_Listener>(
                    Player_KeyBoard_Listener(p1, p2)));
        new_round();
    }

    void update() override {
    	ball.update_pos();

        if(ball.collision(p1)) {
            ball.update_trajectory(p1);
        } else if (ball.collision(p2)) {
            ball.update_trajectory(p2);
        }

        if(ball.get_y() <= 0 || ball.get_y() >= height-10) {
            ball.update_trajectory();
        }
        if(ball.get_x() <= 0 || ball.get_x() >= width-50) {
            enqueue_events(RESET);
        }
        render();
    }

    void render() override {
        graphics.draw(background);
        p1.draw();
        p2.draw();
        ball.draw();
        SDL_RenderPresent(renderer);
    }

};



public:
    Pong(std::string title) : Game(), p1{Player(15, 250)}, p2{Player(750,250)} {
    }
};

int main(int argc, char*argv[]) {
    Game pong = Game(Context(800, 600));
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
            }
        }
        game.update_screen();
    }
}
