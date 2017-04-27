//
// Created by david on 4/27/17.
//

#include "Logger.h"

void Tedm::Logger::log(Tedm::Logger::Level level, std::string msg) {
    if(level >= getLevel()) {
        std::cout << Tedm::Logger::level_strings[int(level)] << ": " << msg << std::endl;
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

void Tedm::Logger::log_error(std::string msg) {
    log(Level::LOG_ERROR, msg);
}

void Tedm::Logger::log_warning(std::string msg) {
    log(Level::LOG_WARN, msg);
}

void Tedm::Logger::log_info(std::string msg) {
    log(Level::LOG_INFO, msg);
}

void Tedm::Logger::log_debug(std::string msg) {
    log(Level::LOG_DEBUG, msg);
}
