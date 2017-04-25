//
// Created by David on 4/24/2017.
//

#ifndef TEDM_INPUT_H
#define TEDM_INPUT_H

#include <vector>
#include <SDL2/SDL.h>
#include "KeyboardEvent.h"

class Input {
private:
    bool enabled;
    std::vector<KeyboardEvent> events;
public:
    void addKeyEvent(SDL_Keycode key_type, KeyboardEvent k);
};


#endif //TEDM_INPUT_H