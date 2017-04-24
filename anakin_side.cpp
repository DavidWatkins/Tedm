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
    const int HEIGHT = 75;
    const int WIDTH  = 73;
    void set_frame(int x, int y) {
        sprite.set_source_pos(WIDTH*x, HEIGHT*y);
    }
    public:

    Player(std::string name, const int x, const int y) : \
        Player_base(name,x,y,75,73) {
        set_pos(x, y);
    }

    void set_pos(int x, int y){
        pos.x = x;
        pos.y = y;
        sprite.set_position(x, y);
    }

    void jump() {
        set_frame(3, 0);
        /*set_y(get_y() - move_distance);

        if(get_y() < 0) {
            set_y(0);
        }
        sprite.set_position(get_x(), get_y());*/
    }

    void duck() {
        set_frame(0, 0);
    }

    void neutral() {
        set_frame(0, 0);
    }

    void move_right() {
        set_frame(0, 0);
        set_y(get_y() + move_distance);
        if(get_y() > 500) {
            set_y(500);
        }
        sprite.set_position(get_x(), get_y());
    }

    void move_left() {
        set_frame(0, 0);
        set_y(get_y() + move_distance);
        if(get_y() > 500) {
            set_y(500);
        }
        sprite.set_position(get_x(), get_y());
    }



    int get_height() {
        return HEIGHT;
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
    enum CONTROLS {P_JUMP, P_DUCK, P_MOVE_RIGHT, P_MOVE_LEFT};

public:
    enum EVENTS {RESET};
    Anakin_side_scroller(std::string title, std::string title_screen_filename, \
         int screen_width, int screen_height, std::string config_file) :
         Game(title,title_screen_filename, screen_width, screen_height),
         p{Player("player_1", 15,250)}  {
        Graphics::init(&window, &renderer, SCREEN_HEIGHT, SCREEN_WIDTH, "Sand is course");
        map<string, function<void()>> keymap;
        cerr << "made map" << endl;
        keymap.insert(make_pair("jump", bind(&Player::jump, &p)));
        keymap.insert(make_pair("duck", bind(&Player::duck, &p)));
        keymap.insert(make_pair("move_right", bind(&Player::move_right, &p)));
        keymap.insert(make_pair("move_down", bind(&Player::move_left, &p)));
        cerr << "inserted keys" << endl;
        map<std::string, std::pair<SDL_Keycode, std::function<void()>>> \
            str_key_func_map = parse_config(config_file, keymap);
        cerr << "parsed config" << endl;
        add_control("jump", keymap, str_key_func_map);
        cerr << "added jump" << endl;
        add_control("duck", keymap, str_key_func_map);
        add_control("move_left", keymap, str_key_func_map);
        cerr << "added move_left" << endl;
        add_control("move_right", keymap, str_key_func_map);
        cerr << "added controls" << endl;

        background = Graphics::add_background(renderer, title_screen_filename);

        add_player(p, "resources/anakin.png");
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

    void update_screen() {
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
    Anakin_side_scroller game = Anakin_side_scroller("Anakin", "resources/anakin_title.jpeg", 800, 600, "anakin.cfg");
    cerr << "Made game" << endl;
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
