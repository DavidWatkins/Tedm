/** 
    game_state_hpp
*/

#include <map>

class Game_state_base {
    std::string name;
    Environment environment;
public:
    Game_state_base(std::string name, Environment &e);
    std_string get_name();
}

class Game_state {
    std::string 
    std::map<std::string, Game_state_base> states;
public:
    Game_state();
    add_state(Game_state_base &state);
}
