/****************************************************************************
 *                                                                          *
 * This file is part of Tedm.                                               *
 *                                                                          *
 *   Tedm is free software: you can redistribute it and/or modify it        *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Box is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Tedm.  If not, see <http://www.gnu.org/licenses/>.  *
 ****************************************************************************/

/**
 * @file pong.cpp
 * @author David Watkins, Theodore Ahlfeld, and Matthew Haigh
 * @date 27 April 2017
 * @brief Simple example game demonstrating Tedm API
 *
 * This is a basic implementation of Pong.
 */

#include <vector>
#include <math.h>
#include "Game.h"
#include "objects/player.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

using namespace std;
using namespace Tedm;

/**
 * @brief the user makes a Player class which inherits Player_base and defines
 * functionality specific to their game. This includes default size, position, 
 * functions for user input, etc.
 * @see Player_base
*/
class Player : public Player_base {
    const unsigned int move_distance = 40;
    const int HEIGHT = 100;
    const int WIDTH  = 10;
public:

    /**
     * @brief The Player inherits Player_base and sets the position 
     * @param x The starting x coordinate
     * @param y The starting y coordinate
    */
    Player(Graphics &g, std::string filename, const int x, const int y) : Player_base(g, filename, x,y,100,10) {
        set_pos(x, y);
    }

    /**
     * @brief Sets the position of the player
     * @param x The starting x coordinate
     * @param y The starting y coordinate
    */
    void set_pos(int x, int y){
        pos.x = x;
        pos.y = y;
        sprite.set_position(x, y);
    }

    /**
     * @brief Move up when the user enters the up key 
    */
    void move_up() {
        set_y(get_y() - move_distance);
        if(get_y() < 0) {
            set_y(0);
        }
        sprite.set_position(get_x(), get_y());
    }

    /**
     * @brief Move down when the user enters the up key 
    */
    void move_down() {
        set_y(get_y() + move_distance);
        if(get_y() > 500) {
            set_y(500);
        }
        sprite.set_position(get_x(), get_y());
    }
    
    /**
     * @brief Get the players y coordinate position
     * @return the y coordinate position
    */
    int get_y() {
        return Object::get_y();
    }

    /**
     * @brief Get the height of the player object
     * @return the height
    */
    int get_height() {
        return HEIGHT;
    }
};

/**
 * @brief the user makes a class for any object type in the game.
 * In this case the ball is the only non-player object
 * @see Object
*/
class Ball : public Object {
    const double MAXBOUNCEANGLE = M_PI/12;
    double vx, vy;
    int start_x;
    int start_y;
    double ballSpeed;

public:
    /**
     * @brief The Ball constructor sets the height, weight, position, and
     * position of the sprite within the image. 
     * @param posx the x coordinate
     * @param posy the y coordinate
     * @param srcx the x coordinate of the sprite within the image
     * @param srcy the y coordinate of the sprite within the image
    */
    Ball(Graphics &g, std::string filename, int posx, int posy, int srcx, int srcy) : Object(g, filename, posx,posy,10,50) {
        sprite.set_source_pos(srcx, srcy);
        sprite.set_height_width(10, 50);
        start_x = posx;
        start_y = posy;
        reset();
    }
    
    /**
     * @brief Return the ball to starting position and set the speed to 
     * default(1)
     */ 
    void reset() {
        pos.x = start_x;
        pos.y = start_y;
        vx = 1;
        vy = 0;
    }

    /**
     * @brief Change the trajectory of ball based on the position of contact
     * with the paddle
     * @param p the paddle which made contact
     * 
     * @see https://gamedev.stackexchange.com/questions/4253/in-pong-how-do-you-
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
    
    /**
     * @brief Reverse trajectory upon direct contact
     */
    void update_trajectory() {
        vy=-vy;
    }

    /**
     * @brief Move the ball each frame based on velocity
     */
    void update_pos() {
        pos.y += round(vy);
        pos.x += round(vx);
        sprite.set_position(pos.x, pos.y);
    }

    /**
     * @brief Set the image to represent the Ball
     * @filename The file path to the image
     */
    void set_sprite(string filename) {
        sprite.set_sprite(filename);
    }

    /**
     * @brief Get the x coordinate position
     * @return the x coordinate position
     */
    int get_x() {
        return pos.x;
    }

    /**
     * @brief Get the y coordinate position
     * @return the y coordinate position
     */
    int get_y() {
        return pos.y;
    }
};

/**
 * @brief The user greates a KeyEventListener class to define the functions
 * that will execute in response to user input, inheriting the KeyEventListener
 * class and overriding the appropriate virtual functions. 
 */
class Player_KeyBoard_Listener : public KeyEventListener {
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

class Quit_Listener : public EventListener {
    bool &isRunning;
public:
    Quit_Listener(bool &b) : isRunning(b) {
    }

    void operator()() override {
        isRunning = false;
    }
};

/**
 * @brief The user creates State class for each game state  which inherits the 
 * State class and implements elements specific to the state
 */
class Pong_State : public State {
public:
    Player p1, p2;
    Ball ball;
    
    /**
     * @brief The constructor initializes the paddles and ball.
     * @param game the main Game object
     */
    Pong_State(Game &game) :
            State(game, "pong"),
            p1{Player(graphics, "../resources/blue1.png", 15, 250)},
            p2{Player(graphics, "../resources/blue1.png", 750, 250)},
            ball{Ball(graphics, "../resources/blaster.png", 375, 295, 0, 0)} {}

    SDL_Texture *background;

    /**
     * @brief reset positions of paddle and ball for new round
     */
    void new_round() {
        p1.set_pos(15,250);
        p2.set_pos(750, 250);
        ball.reset();
    }

    /**
     * @brief Override the default init() function to set default conditions
     * for a new game
     * @return true if success
     */
    bool init() override {
        game.setWindowTitle("Dat Pong");
        background = graphics.add_background("../resources/dat_anakin.jpg");
        eventHandler.addKeyDownListener(
                make_shared<Player_KeyBoard_Listener>(
                        Player_KeyBoard_Listener(p1, p2)));
        eventHandler.addExitListener(
                make_shared<Quit_Listener>(
                        Quit_Listener(context.isRunning)));
        context.targetFramerate = 1000;
        new_round();
        return true;
    }

    /**
     * @brief Remove state event listeners so they do not interfere with the 
     * following state
     */
    void destroy() override {

    }

    /**
     * @brief Pause the game
     */ 
    void paused() override {
        //context.isPaused = true;
    }

    /**
     * @brief Unpause the game
     */ 
    void resumed() override {
        //context.isPaused = false;
    }

    /**
     * @brief the game will call the update() function every frame,
     * executing the main functionality of the game. Primary game logic
     * goes here
     */
    void update() override {
        ball.update_pos();

        if(ball.collision(p1)) {
            ball.update_trajectory(p1);
        } else if (ball.collision(p2)) {
            ball.update_trajectory(p2);
        }

        if(ball.get_y() <= 0 || ball.get_y() >= context.height-10) {
            ball.update_trajectory();
        }
        if(ball.get_x() <= 0 || ball.get_x() >= context.width-50) {
            new_round();
        }
        //render();
    }

    /**
     * @brief the game will call render after update each frame. This function
     * draws everything relevant for the current state
     */
    void render() override {
        graphics.draw(background);
        p1.draw();
        p2.draw();
        ball.draw();
    }

};

int main(int argc, char*argv[]) {
    Game pong = Game();
    Pong_State pong_state(pong);
    pong.registerState("", make_shared<Pong_State>(pong_state));
    pong.mainLoop();
}
