//
// Created by David on 4/24/2017.
//

#include <vector>
#include <math.h>
#include "src/utils/Game.h"
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

class Pong_State : public State {
    Player p1, p2;
    Ball ball;
    
    SDL_Texture *background;

    void new_round() {
        p1.set_pos(15,250);
        p2.set_pos(750, 250);
        ball.reset();
    }

    bool init() override {
        p1 = Player(15,250);
        p2 = Player(750,250);
        ball = Ball(375,295, 0, 0);
        parent->setWindowTitle("Dat Pong");
        background = graphics.add_background("resources/dat_anaking.jpg");
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
        graphics.draw(p1);
        graphics.draw(p2);
        graphics.draw(ball);
        SDL_RenderPresent(renderer);
    }
    
};

class player_event_listener : KeyEventListener {
public:
    void operator()(SDL_Keycode sym) override {
        switch(sym) {
            case SDL_w:
                p1.move_up();
                break;
            case SDL_s:
                p1.move_down();
                break;
            case SDL_UP:
                p2.move_up();
                break;
            case SDL_DOWN:
                p2.move_down();
                break;
        }
    }
}

public:
    Pong(std::string title) : Game(), p1{Player(15, 250)}, p2{Player(750,250)} {
        eventHandler.OnKeyDown(make_shared<player_event_listener>(player_event_listener()));
    }
};

int main(int argc, char*argv[]) {
    //Pong game = Pong("pong", "resources/dat_anakin.jpg", 800, 600, "demos/pong.cfg");
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
