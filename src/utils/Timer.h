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
 *  @file    Timer.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Timer for maintaining frame rate
 *
 *  @see http://lazyfoo.net/tutorials/SDL/14_animated_sprites_and_vsync/index.php
 *
 */

#ifndef __TIMER_HPP__
#define __TIMER_HPP__

#include <SDL2/SDL.h>
/**
 *  @brief Timer for maintaining frame rate
 */
class Timer
{
    private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;

    public:
    /**
     * @brief Constructori
     */
    Timer();

    //The various clock actions
    
    /**
     * @brief start the timer
     */
    void start();
    /**
     * @brief stop the timer
     */
    void stop();
    /**
     * @brief pause the timer
     */
    void pause();
    /**
     * @brief unpause the timer
     */
    void unpause();

    /**
     * @brief check the number of ticks since timer started
     * @return the quantity of ticks since timer started
     */
    int get_ticks();

    /**
     * @brief Checks the status of the timer
     * @return true if timer is running
     */
    bool is_started();

    /**
     * @brief Check if timer is paused
     * @return true if timer is paused
     */
    bool is_paused();
};

#endif /* __TIMER_HPP__ */
