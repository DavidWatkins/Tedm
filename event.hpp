/**
  event.cpp
Purpose: Define event for game object to subscribe/respond to 
*/

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <map>
#include <vector>

template<typename T>
class Event {
    T action;
    Event(T& t) {
        action = t;
    }
};

#endif /* __EVENT_HPP__ */

