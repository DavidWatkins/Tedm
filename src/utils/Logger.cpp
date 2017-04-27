//
// Created by david on 4/27/17.
//

#include "Logger.h"

#define _LOG(level) \
    std::cout << Tedm::Logger::level_strings[int(level)] << " " __FILE__  ":"  << __LINE__ << ": "

void Tedm::Logger::log(Tedm::Logger::Level level, std::string msg) {
    if(level > getLevel()) {
        _LOG(level) << msg << std::endl;
    }
}

Tedm::Logger::Level Tedm::Logger::getLevel() {
    return level;
}

void Tedm::Logger::setLevel(Tedm::Logger::Level level) {
    Tedm::Logger::level = level;
}

Tedm::Logger::Logger(Tedm::Logger::Level level) {
    Tedm::Logger::level = level;
}

Tedm::Logger::~Logger() { }
