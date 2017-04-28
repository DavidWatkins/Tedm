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
 *  @file    logger.cpp
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Logger for debugging
 *
 */

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
