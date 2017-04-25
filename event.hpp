/**
  event.cpp
Purpose: Define event for game object to subscribe/respond to
*/

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <map>
#include <vector>
#include <iostream>

//template<typename T>
class Event {
    std::function<void()> action;
public:
    Event(std::function<void()> e) {
        action = e;
    }
    void operator()() {action();}
};

#endif /* __EVENT_HPP__ */

