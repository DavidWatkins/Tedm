/**
    environment.cpp
    Purpose: Describe level environment
*/

#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include "player.hpp"
#include "event.hpp"
#include <string>
#include <iostream>
#include <fstream>

class Environment {
    std::ofstream background_file;
public:
    Environment();
    Environment(std::string filename);
    ~Environment();
    void add_background(std::string filename);
};

#endif /* __ENVIRONMENT_HPP__ */

