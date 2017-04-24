//
// Created by David on 4/24/2017.
//

#ifndef TEDM_INPUT_H
#define TEDM_INPUT_H


class Input {
private:
    bool enabled;
    vector<KeyboardEvents> events;
public:
    addKeyEvent(int key_type, KeyboardEvent k);
};


#endif //TEDM_INPUT_H