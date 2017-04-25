/**
    state.cpp
    Purpose: Describe state of any in-game object
*/

#ifndef __STATE_HPP__
#define __STATE_HPP__

#include "event.hpp"
#include <queue>

template<typename T>
class State_base {
    std::queue<Event<T>> pending_events;
public:
    State_base() {
        pending_events = std::queue<Event<T>>();
    }
    bool is_busy() {
        return !pending_events.empty();
    }
};

#endif /* __STATE_HPP__ */

