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
    const unsigned int move_distance {40};
    const int HEIGHT = 100;
    const int WIDTH  = 10;
    public:

    Player(std::string name, const int x, const int y) : \
        Player_base(name,x,y,100,10) {
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
        return Player_base::get_y();
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
    SDL_Texture *background;
    SDL_Renderer *renderer;
    SDL_Window *window;
    Player p1, p2;
    Ball ball;
    enum CONTROLS {P1_MOVE_UP, P1_MOVE_DOWN, P2_MOVE_UP, P2_MOVE_DOWN};

public:
    enum EVENTS {RESET};
    Pong(std::string title, std::string title_screen_filename, \
         int screen_width, int screen_height, std::string config_file) :
         Game(title,title_screen_filename, screen_width, screen_height),
         p1{Player("player_1", 15,250)}, p2{Player("player_2",750,250)} \
             ,ball{Ball(375,295, 0, 0)} {
        map<string, function<void()>> keymap;
        function<void()> f = bind(&Player::move_up, &p1);
        keymap.insert(make_pair("p1_move_up", bind(&Player::move_up, &p1)));
        keymap.insert(make_pair("p1_move_down", bind(&Player::move_down, &p1)));
        keymap.insert(make_pair("p2_move_up", bind(&Player::move_up, &p2)));
        keymap.insert(make_pair("p2_move_down", bind(&Player::move_down, &p2)));
        auto str_key_func_map = parse_config("pong.cfg", keymap);
        buttons.push_back(str_key_func_map.find("p1_move_up")->second.first);
        functions.push_back(str_key_func_map.find("p1_move_up")->second.second);
        buttons.push_back(str_key_func_map.find("p1_move_down")->second.first);
        functions.push_back(str_key_func_map.find("p1_move_down")->second.second);
        buttons.push_back(str_key_func_map.find("p2_move_up")->second.first);
        functions.push_back(str_key_func_map.find("p2_move_up")->second.second);
        buttons.push_back(str_key_func_map.find("p2_move_down")->second.first);
        functions.push_back(str_key_func_map.find("p2_move_down")->second.second);
        Graphics::init(&window, &renderer, screen_height, screen_width, title);
        background = Graphics::add_background(renderer, title_screen_filename);

        Pong::add_player(p1, "resources/blue1.png");
        Pong::add_player(p2, "resources/blue1.png");
        ball.set_sprite(renderer, "resources/blaster.png");
        objects.push_back(&ball);
    }

    ~Pong() {
        //Destroy window
        SDL_DestroyWindow( window );
        //Quit SDL subsystems
        SDL_Quit();
    }

    void add_player(Player &p, std::string image) {
        p.set_sprite(renderer, image);
        Game::add_player(p);
    }

    void enqueue_events(EVENTS e) {
        switch(e) {
            case RESET:
                new_round();
                break;
        }
    }

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
        for(Object *o : objects) {
            SDL_Rect *rc = o->sprite.get_pos();
            SDL_Texture *sprite = o->sprite.get_sprite();
            SDL_RenderCopy(renderer, sprite, &o->sprite.src, &o->sprite.tgt);
        }
        SDL_RenderPresent(renderer);
    }
};

int main(int argc, char*argv[]) {
    Pong game = Pong("pong", "resources/dat_anakin.jpg", 800, 600, "pong.ini");
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
