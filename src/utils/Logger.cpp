//
// Created by david on 4/27/17.
//

#include "Logger.h"

namespace Tedm {
    void Logger::log(Logger::LogLevel msg_level, std::string msg) {
        if(msg_level >= getLevel()) {
            std::cout << Logger::level_strings[int(msg_level)] << ": " << msg << std::endl;
        }
    }

    Logger::LogLevel Logger::getLevel() {
        return Logger::level;
    }

    void Logger::setLevel(Logger::LogLevel level) {
        Logger::level = level;
    }

    void Logger::log_error(std::string msg) {
        log(Logger::LogLevel::LOG_ERROR, msg);
    }

    void Logger::log_warning(std::string msg) {
        log(Logger::LogLevel::LOG_WARN, msg);
    }

    void Logger::log_info(std::string msg) {
        log(Logger::LogLevel::LOG_INFO, msg);
    }

    void Logger::log_debug(std::string msg) {
        log(Logger::LogLevel::LOG_DEBUG, msg);
    }

    const std::string Logger::level_strings[5] = {
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR",
        "NONE"
    };

    Logger::LogLevel Logger::level = Logger::LogLevel::LOG_NONE;
}