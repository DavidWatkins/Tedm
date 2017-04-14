#include <vector>
#include "game.hpp"
#include "event.hpp"
#include "state.hpp"
#include "player.hpp"
#include "sprite.hpp"
#include "drawable.hpp"

class Player : public Player_base, public Drawable {
public:
    const unsigned int move_distance {10};
    Player(const int x, const int y) : Player_base(x,y,100,10) {
        set_rc(x,y,100,10);
    }

    void set_pos(int x, int y){
        pos.x = rc.x = x;
        pos.y = rc.y = y;
    }

    void set_sprite(SDL_Renderer *renderer, std::string filename) {
        sprite = Sprite_base(renderer, filename);
    }

    void move_up() {
        pos.y = rc.y-=move_distance;
        if(pos.y < 0) {
            pos.y = rc.y = 0;
        }
    }

    void move_down() {
        pos.y = rc.y+=move_distance;
        if(pos.y < 500) {
            pos.y = rc.y = 500;
        }
    }
};

class Ball : public Collidable, public Drawable {
    public:
    Ball(int x, int y) : Collidable(x,y,10,50) {
        set_rc(pos.x, pos.y, size.h, size.w);
    }

    void set_sprite(SDL_Renderer *renderer, std::string filename) {
        sprite = Sprite_base(renderer, filename);
    }
};

class Pong : public Game {
private:
    std::vector<Player *> players;
    std::vector<Drawable *> drawables;
    SDL_Renderer *renderer;
    SDL_Texture *background;
    SDL_Window *window;
    Player p1, p2;
    Ball ball;

public:
    enum EVENTS {P1_MOVE_UP, P1_MOVE_DOWN, P2_MOVE_UP, P2_MOVE_DOWN, GAME_END};
    Pong(std::string title, std::string title_screen_filename, \
                int screen_width, int screen_height) :
                Game(title,title_screen_filename, screen_width, screen_height),
                p1{Player(15,250)}, p2{Player(750,250)} ,ball{Ball(375,295)} {

        Graphics::init(&window, &renderer, screen_height, screen_width, title);
        background = Graphics::add_background(renderer, title_screen_filename);

        add_player(&p1);
        add_player(&p2);
        ball.set_sprite(renderer, "resources/blue.png");
        collidables.push_back(&ball);
        drawables.push_back(&ball);
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

    void add_player(Player *p) {
        p->set_sprite(renderer, "resources/blue.png");
        players.push_back(p);
        collidables.push_back(p);
        drawables.push_back(p);
    }

    void update_screen() {
        for(auto *p : drawables) {
            SDL_Rect *rc = p->get_rc();
            SDL_Texture *sprite = p->get_sprite();
            SDL_Rect bg_redraw;
            bg_redraw.x = rc->x-10;
            bg_redraw.y = rc->y-10;
            bg_redraw.h = rc->h+20;
            bg_redraw.w = rc->w+20;
            Graphics::update_screen(renderer, background, &bg_redraw);
            Graphics::update_screen(renderer, sprite, rc);
            SDL_RenderPresent(renderer);
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
                        game.update_screen();
                        game.enqueue_events(Pong::EVENTS::P1_MOVE_UP);
                    break;
                    case SDLK_s:
                        game.update_screen();
                        game.enqueue_events(Pong::EVENTS::P1_MOVE_DOWN);
                    break;
                    case SDLK_UP:
                        game.update_screen();
                        game.enqueue_events(Pong::EVENTS::P2_MOVE_UP);
                    break;
                    case SDLK_DOWN:
                        game.update_screen();
                        game.enqueue_events(Pong::EVENTS::P2_MOVE_DOWN);
                    break;
                }
            }
        }
    }
}
