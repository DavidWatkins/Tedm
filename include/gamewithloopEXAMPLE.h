////
//// Created by David on 4/24/2017.
////
//
//#ifndef TEDM_GAMEWITHLOOPEXAMPLE_H
//#define TEDM_GAMEWITHLOOPEXAMPLE_H
//
//#include <algorithm>
//#include <sstream>
//#include "state.hpp"
//#include "environment.hpp"
//#include "event.hpp"
//#include "graphics.hpp"
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <queue>
//#include <map>
//#include "Input.h"
//
//class gamewithloopEXAMPLE {
//    protected:
//        int height;
//        int width;
//        std::string name;
//        std::vector<Player_base *> players;
//        std::vector<Object *> objects;
//        std::vector<SDL_Keycode> buttons;
//        std::vector<std::function<void()>> functions;
//        Input i;
//        int update_interval;
//
//    public:
//        Game(std::string title, std::string title_screen_filename, \
//            int screen_width=SCREEN_WIDTH, int screen_height=SCREEN_HEIGHT);
//
//        void add_control(std::string func,
//                         std::map<std::string,std::function<void()>> &str_func_map,
//                         std::map<std::string, std::pair
//                                 <SDL_Keycode, std::function<void()>>> &str_key_func_map);
//
//        void enqueue_event() {
//
//        }
//        void add_player(Player_base &player);
//        void remove_player(Player_base *player);
//        bool collision(Object &obj);
//        std::map<std::string, std::pair<SDL_Keycode, std::function<void()>>>
//                parse_config(
//                std::string config_file,
//                std::map<std::string, std::function<void()>> func_map);
//        void handle_keypress(SDL_Keycode key);
//
//        void boot();
//        void update();
//        void render();
//
//        void main_loop();
//};
//
//#endif //TEDM_GAMEWITHLOOPEXAMPLE_H
