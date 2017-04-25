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
    const unsigned int move_distance {8};
    const int HEIGHT = 72;
    const int WIDTH  = 73;
    bool facing_right;
    void set_frame(int x, int y) {
        sprite.set_source_pos(WIDTH*x, HEIGHT*y);
    }
    public:

    Player(std::string name, const int x, const int y) : \
        Player_base(name,x,y,72,73) {
        set_pos(x, y);
        facing_right = true;
    }

    void set_pos(int x, int y){
        pos.x = x;
        pos.y = y;
        sprite.set_position(x, y);
    }

    //void jump() {
     //   set_frame(3, 0);
        /*set_y(get_y() - move_distance);

        if(get_y() < 0) {
            set_y(0);
        }
        sprite.set_position(get_x(), get_y());*/
    //}

    void duck() {
        if (facing_right) {
            set_frame(3, 4);
        } else  {
            set_frame(4, 4);
        }
    }

    void attack() {
        cerr << "Attacking" << endl;
        if (facing_right) {
            state.enqueue_event(Event{bind(&Player::set_frame, this, 0, 4)});
            state.enqueue_event(Event{bind(&Player::set_frame, this, 1, 4)});
            state.enqueue_event(Event{bind(&Player::set_frame, this, 2, 4)});
            //state.enqueue_event(Event{bind(&Player::set_frame, this, 3, 4)});
        } else {
            //facing left
            state.enqueue_event(Event{bind(&Player::set_frame, this, 7, 4)});
            state.enqueue_event(Event{bind(&Player::set_frame, this, 6, 4)});
            state.enqueue_event(Event{bind(&Player::set_frame, this, 5, 4)});
            //state.enqueue_event(Event{bind(&Player::set_frame, this, 4, 4)});
        }
    }

    void neutral() {
        set_frame(0, 0);
    }

    void move_right() {
        SDL_Rect *src = sprite.get_src();
        set_frame(((src->x + 1) % 4), 0);
        set_x(get_x() + move_distance);
        if(get_x() > 600) {
            //next screen
            set_x(600);
        }
        sprite.set_position(get_x(), get_y());
        facing_right = true;
    }

    void move_left() {
        SDL_Rect *src = sprite.get_src();
        set_frame((((src->x + 1) % 4)+4), 0);
        set_x(get_x() - move_distance);
        if(get_x() < 15) {
            set_x(15);
        }
        sprite.set_position(get_x(), get_y());
        facing_right = false;
    }

    int get_height() {
        return HEIGHT;
    }

    int get_width() {
        return WIDTH;
    }

};

class Block : public Object {

};

class Anakin_side_scroller : public Game {
private:
    SDL_Texture *background;
    SDL_Renderer *renderer;
    SDL_Window *window;
    Player p;
    enum CONTROLS {P_DUCK, P_MOVE_RIGHT, P_MOVE_LEFT, P_ATTACK, P_START};

public:
    enum EVENTS {RESET};
    Anakin_side_scroller(std::string title, std::string title_screen_filename, \
         int screen_width, int screen_height, std::string config_file) :
         Game(title,title_screen_filename, screen_width, screen_height),
         p{Player("player_1", 15,250)}  {
        Graphics::init(&window, &renderer, SCREEN_HEIGHT, SCREEN_WIDTH, "Sand is course");
        map<string, Event> keymap;
        keymap.insert(make_pair("duck", Event{bind(&Player::duck, &p)}));
        keymap.insert(make_pair("move_right", Event{bind(&Player::move_right, &p)}));
        keymap.insert(make_pair("move_left", Event{bind(&Player::move_left, &p)}));
        keymap.insert(make_pair("attack", Event{bind(&Player::attack, &p)}));
        map<std::string, std::pair<SDL_Keycode, Event>> \
            str_key_func_map = parse_config(config_file, keymap);
        add_control("duck", keymap, str_key_func_map);
        add_control("move_left", keymap, str_key_func_map);
        add_control("move_right", keymap, str_key_func_map);
        add_control("attack", keymap, str_key_func_map);

        background = Graphics::add_background(renderer, title_screen_filename);

        add_player(p, "resources/anakin1.png");
    }

    ~Anakin_side_scroller() {
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
        p.set_pos(15,250);
    }

    void update_screen() override {
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
    Anakin_side_scroller game = Anakin_side_scroller("Anakin", "resources/anakin_title.jpeg", 800, 600, "demos/anakin.cfg");
    std::cout << "Game Loaded" << std::endl;
    game.run();
}
