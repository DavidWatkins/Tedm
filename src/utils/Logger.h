//
// Created by david on 4/27/17.
//

#ifndef TEDM_LOGGER_H
#define TEDM_LOGGER_H

#include <iostream>

namespace Tedm {

    class Logger {
    public:

        enum LogLevel {
            LOG_DEBUG = 1,
            LOG_INFO = 2,
            LOG_WARN = 3,
            LOG_ERROR = 4,
            LOG_NONE = 5,
        };

        static const std::string level_strings[];

        Logger() {}

        static void log(LogLevel level, std::string msg);

        static void log_error(std::string msg);
        static void log_warning(std::string msg);
        static void log_info(std::string msg);
        static void log_debug(std::string msg);

        static LogLevel getLevel();

        static void setLevel(LogLevel level);

    private:
        static LogLevel level;
    };
}

#endif //TEDM_LOGGER_H
