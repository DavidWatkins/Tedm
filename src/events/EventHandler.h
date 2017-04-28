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
 *  @file    EventHandler.h
 *  @author  David Watkins, Theodore Ahlfeld, Matthew Haigh
 *  @date    4/27/2017
 *  @version 1.0
 *
 *  @brief Create handlers for Events so developers can indicate which events
 *  their game will respond to.
 *  @see http://www.sdltutorials.com/sdl-events
 *
 */

#ifndef TEDM_EVENTHANDLER_H
#define TEDM_EVENTHANDLER_H

#include <vector>
#include <algorithm>
#include <memory>

#include "Event.h"
#include "EventListener.h"
#include "EventTrigger.h"

namespace Tedm {
    class EventHandler {
    public:
        /**
         * @brief Add listener for keydown event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addKeyDownListener(std::shared_ptr<KeyEventListener> eventListener) { _KeyDownEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for keyup event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addKeyUpListener(std::shared_ptr<KeyEventListener> eventListener) { _KeyUpEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for mouse move event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addMouseMoveListener(std::shared_ptr<MouseMoveListener> eventListener) { _MouseMoveEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for mouse wheel event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addMouseWheelListener(std::shared_ptr<MouseWheelListener> eventListener) { _MouseWheelEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for left mouse button down event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addLButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) { _LButtonDownEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for left mouse button up event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addLButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) { _LButtonUpEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for right mouse button down event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addRButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) { _RButtonDownEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for right mouse button up event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addRButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) { _RButtonUpEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for middle mouse button down event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addMButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) { _MButtonDownEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for middle mouse button up event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addMButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) { _MButtonUpEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for exit event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addExitListener(std::shared_ptr<EventListener> eventListener) { _ExitEvents.push_back(eventListener); }
        
        /**
         * @brief Add listener for user event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void addUserListener(std::shared_ptr<UserListener> eventListener) { _UserEvents.push_back(eventListener); }

        /**
         * @brief Remove listener for keydown event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeKeyDownListener(std::shared_ptr<KeyEventListener> eventListener) {
            _KeyDownEvents.erase(std::remove(_KeyDownEvents.begin(), _KeyDownEvents.end(), eventListener));
        }

        /**
         * @brief Remove listener for keyup event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeKeyUpListener(std::shared_ptr<KeyEventListener> eventListener) {
            _KeyUpEvents.erase(std::remove(_KeyUpEvents.begin(), _KeyUpEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for mouse move event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeMouseMoveListener(std::shared_ptr<MouseMoveListener> eventListener) {
            _MouseMoveEvents.erase(std::remove(_MouseMoveEvents.begin(), _MouseMoveEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for mouse wheel event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeMouseWheelListener(std::shared_ptr<MouseWheelListener> eventListener) {
            _MouseWheelEvents.erase(std::remove(_MouseWheelEvents.begin(), _MouseWheelEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for left mouse button down event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeLButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _LButtonDownEvents.erase(std::remove(_LButtonDownEvents.begin(), _LButtonDownEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for left mouse button up event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeLButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _LButtonUpEvents.erase(std::remove(_LButtonUpEvents.begin(), _LButtonUpEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for right mouse button down event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeRButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _RButtonDownEvents.erase(std::remove(_RButtonDownEvents.begin(), _RButtonDownEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for right mouse button up event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeRButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _RButtonUpEvents.erase(std::remove(_RButtonUpEvents.begin(), _RButtonUpEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for middle mouse button down event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeMButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _MButtonDownEvents.erase(std::remove(_MButtonDownEvents.begin(), _MButtonDownEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for right mouse button up event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeMButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _MButtonUpEvents.erase(std::remove(_MButtonUpEvents.begin(), _MButtonUpEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for exit event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeExitListener(std::shared_ptr<EventListener> eventListener) {
            _ExitEvents.erase(std::remove(_ExitEvents.begin(), _ExitEvents.end(), eventListener));
        }
        
        /**
         * @brief Remove listener for user event
         * @param eventListener the listener which defines the action to occur
         * upon event
         */
        void removeUserListener(std::shared_ptr<UserListener> eventListener) {
            _UserEvents.erase(std::remove(_UserEvents.begin(), _UserEvents.end(), eventListener));
        }
        
        /**
         * @brief Add event trigger to be checked
         * Event triggers are custom events which are not standard input
         * @param trigger the custom event trigger to be added 
         */
        virtual void addTrigger(std::shared_ptr<EventTrigger> trigger);
        
        /**
         * @brief Remove event trigger
         * @param trigger the item to remove
         */
        virtual void removeTrigger(std::shared_ptr<EventTrigger> trigger);

        /**
         * @brief check all registered event listeners 
         */
        void checkListeners();

        /**
         * @brief When an event has occurred, check for listeners and process
         * handlers
         */
        void process();

    protected:
        std::vector<std::shared_ptr<EventListener>> _ExitEvents;
        std::vector<std::shared_ptr<UserListener>> _UserEvents;

        std::vector<std::shared_ptr<MouseButtonListener>> _LButtonDownEvents;
        std::vector<std::shared_ptr<MouseButtonListener>> _LButtonUpEvents;
        std::vector<std::shared_ptr<MouseButtonListener>> _RButtonDownEvents;
        std::vector<std::shared_ptr<MouseButtonListener>> _RButtonUpEvents;
        std::vector<std::shared_ptr<MouseButtonListener>> _MButtonDownEvents;
        std::vector<std::shared_ptr<MouseButtonListener>> _MButtonUpEvents;

        std::vector<std::shared_ptr<MouseMoveListener>> _MouseMoveEvents;

        std::vector<std::shared_ptr<MouseWheelListener>> _MouseWheelEvents;

        std::vector<std::shared_ptr<KeyEventListener>> _KeyDownEvents;
        std::vector<std::shared_ptr<KeyEventListener>> _KeyUpEvents;

        std::vector<std::shared_ptr<EventTrigger>> _eventTriggers;

        Event event;
    };
}

#endif //TEDM_EVENTHANDLER_H
