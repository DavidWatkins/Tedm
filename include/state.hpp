/**
    state.cpp
    Purpose: Describe state of any in-game object
*/

#ifndef __STATE_HPP__
#define __STATE_HPP__

#include "event.hpp"
#include <queue>
#include <iostream>

//template<typename T>
class State_base {
    std::queue<Event> pending_events;
public:
    State_base() {
        pending_events = std::queue<Event>();
    }
    bool is_busy() {
        return !pending_events.empty();
    }
    void enqueue_event(Event e) {
        pending_events.push(e);
    }

    void dequeue_event() {
        pending_events.front()();
        pending_events.pop();
    }
};

#endif /* __STATE_HPP__ */

