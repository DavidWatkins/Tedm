/**
    state.cpp
    Purpose: Describe state of any in-game object
*/

#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <queue>
#include <iostream>
#include "events/Event.h"

//template<typename T>
class State_base {
    std::queue<Event> pending_events;
public:
    State_base() {
        pending_events = std::queue<Event>();
    }
    bool pending() {
        return !pending_events.empty();
    }
    void enqueue_event(Event e) {
        pending_events.push(e);
    }

    void dequeue_event() {
        //execute the event
        pending_events.front()();
        pending_events.pop();
    }
};

#endif /* __STATE_HPP__ */

