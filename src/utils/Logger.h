/****************************************************************************
 *                                                                          *
 * This file is part of Tedm.                                               *
 *                                                                          *
 *   Tedm is free software: you can redistribute it and/or modify it        *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Box is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Tedm.  If not, see <http://www.gnu.org/licenses/>.  *
 ****************************************************************************/

/**
 *  @file    logger.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Logger for debugging
 *
 */

#ifndef TEDM_LOGGER_H
#define TEDM_LOGGER_H

#include <iostream>

namespace Tedm {

    /**
    *  @brief Logger for debugging
    */
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

        /**
         * @brief default constructor
         */
        Logger() {}

        /**
         * @brief log a message
         * @param level the logging level
         * @param msg the message
         */
        static void log(LogLevel level, std::string msg);

        /**
         * @brief log a message at error level
         * @param msg the message
         */
        static void log_error(std::string msg);
        
        /**
         * @brief log a message at warning level
         * @param msg the message
         */
        static void log_warning(std::string msg);
        
        /**
         * @brief log a message at info level
         * @param msg the message
         */
        static void log_info(std::string msg);
        
        /**
         * @brief log a message at debug level
         * @param msg the message
         */
        static void log_debug(std::string msg);

        /**
         * @brief Retrieve the current logging level
         * @return the current logging level
         */
        static LogLevel getLevel();

        /**
         * @brief Set the current logging level
         * @param level the new logging level
         */
        static void setLevel(LogLevel level);

    private:
        static LogLevel level;
    };
}

#endif //TEDM_LOGGER_H
