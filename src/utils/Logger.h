//
// Created by david on 4/27/17.
//

#ifndef TEDM_LOGGER_H
#define TEDM_LOGGER_H

#include <iostream>

namespace Tedm {
    class Logger {
    public:
        enum Level {
            LOG_DEBUG = 1,
            LOG_INFO = 2,
            LOG_WARN = 3,
            LOG_ERROR = 4,
            LOG_NONE = 5,
        };

        const std::string level_strings[5] = {
                "DEBUG",
                "INFO",
                "WARN",
                "ERROR",
                "NONE"
        };

        //Logger() : Level(level) {}
        Logger() {}

        Logger(Level level);

        ~Logger();

        void log(Level level, std::string msg);

        void log_error(std::string msg);
        void log_warning(std::string msg);
        void log_info(std::string msg);
        void log_debug(std::string msg);

        static Level getLevel();

        static void setLevel(Level level);

    private:
        static Level level;
    };
}

#endif //TEDM_LOGGER_H
