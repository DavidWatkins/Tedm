//
// http://www.sdltutorials.com/sdl-events
//

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
        void addKeyDownListener(std::shared_ptr<KeyEventListener> eventListener) { _KeyDownEvents.push_back(eventListener); }
        void addKeyUpListener(std::shared_ptr<KeyEventListener> eventListener) { _KeyUpEvents.push_back(eventListener); }
        void addMouseMoveListener(std::shared_ptr<MouseMoveListener> eventListener) { _MouseMoveEvents.push_back(eventListener); }
        void addMouseWheelListener(std::shared_ptr<MouseWheelListener> eventListener) { _MouseWheelEvents.push_back(eventListener); }
        void addLButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) { _LButtonDownEvents.push_back(eventListener); }
        void addLButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) { _LButtonUpEvents.push_back(eventListener); }
        void addRButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) { _RButtonDownEvents.push_back(eventListener); }
        void addRButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) { _RButtonUpEvents.push_back(eventListener); }
        void addMButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) { _MButtonDownEvents.push_back(eventListener); }
        void addMButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) { _MButtonUpEvents.push_back(eventListener); }
        void addExitListener(std::shared_ptr<EventListener> eventListener) { _ExitEvents.push_back(eventListener); }
        void addUserListener(std::shared_ptr<UserListener> eventListener) { _UserEvents.push_back(eventListener); }

        void removeKeyDownListener(std::shared_ptr<KeyEventListener> eventListener) {
            _KeyDownEvents.erase(std::remove(_KeyDownEvents.begin(), _KeyDownEvents.end(), eventListener));
        }
        void removeKeyUpListener(std::shared_ptr<KeyEventListener> eventListener) {
            _KeyUpEvents.erase(std::remove(_KeyUpEvents.begin(), _KeyUpEvents.end(), eventListener));
        }
        void removeMouseMoveListener(std::shared_ptr<MouseMoveListener> eventListener) {
            _MouseMoveEvents.erase(std::remove(_MouseMoveEvents.begin(), _MouseMoveEvents.end(), eventListener));
        }
        void removeMouseWheelListener(std::shared_ptr<MouseWheelListener> eventListener) {
            _MouseWheelEvents.erase(std::remove(_MouseWheelEvents.begin(), _MouseWheelEvents.end(), eventListener));
        }
        void removeLButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _LButtonDownEvents.erase(std::remove(_LButtonDownEvents.begin(), _LButtonDownEvents.end(), eventListener));
        }
        void removeLButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _LButtonUpEvents.erase(std::remove(_LButtonUpEvents.begin(), _LButtonUpEvents.end(), eventListener));
        }
        void removeRButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _RButtonDownEvents.erase(std::remove(_RButtonDownEvents.begin(), _RButtonDownEvents.end(), eventListener));
        }
        void removeRButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _RButtonUpEvents.erase(std::remove(_RButtonUpEvents.begin(), _RButtonUpEvents.end(), eventListener));
        }
        void removeMButtonDownListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _MButtonDownEvents.erase(std::remove(_MButtonDownEvents.begin(), _MButtonDownEvents.end(), eventListener));
        }
        void removeMButtonUpListener(std::shared_ptr<MouseButtonListener> eventListener) {
            _MButtonUpEvents.erase(std::remove(_MButtonUpEvents.begin(), _MButtonUpEvents.end(), eventListener));
        }
        void removeExitListener(std::shared_ptr<EventListener> eventListener) {
            _ExitEvents.erase(std::remove(_ExitEvents.begin(), _ExitEvents.end(), eventListener));
        }
        void removeUserListener(std::shared_ptr<UserListener> eventListener) {
            _UserEvents.erase(std::remove(_UserEvents.begin(), _UserEvents.end(), eventListener));
        }

        virtual void addTrigger(std::shared_ptr<EventTrigger> trigger);
        virtual void removeTrigger(std::shared_ptr<EventTrigger> trigger);

        void checkListeners();

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
