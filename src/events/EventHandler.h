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

namespace Tedm {
    class EventHandler {
    public:
        virtual void OnInputFocus(std::shared_ptr<EventListener> eventListener);

        virtual void OnInputBlur(std::shared_ptr<EventListener> eventListener);

        virtual void OnKeyDown(std::shared_ptr<KeyEventListener> eventListener);

        virtual void OnKeyUp(std::shared_ptr<KeyEventListener> eventListener);

        virtual void OnMouseFocus(std::shared_ptr<EventListener> eventListener);

        virtual void OnMouseBlur(std::shared_ptr<EventListener> eventListener);

        virtual void OnMouseMove(std::shared_ptr<MouseMoveListener> eventListener);

        virtual void OnMouseWheel(std::shared_ptr<MouseWheelListener> eventListener);

        virtual void OnLButtonDown(std::shared_ptr<MouseButtonListener> eventListener);

        virtual void OnLButtonUp(std::shared_ptr<MouseButtonListener> eventListener);

        virtual void OnRButtonDown(std::shared_ptr<MouseButtonListener> eventListener);

        virtual void OnRButtonUp(std::shared_ptr<MouseButtonListener> eventListener);

        virtual void OnMButtonDown(std::shared_ptr<MouseButtonListener> eventListener);

        virtual void OnMButtonUp(std::shared_ptr<MouseButtonListener> eventListener);

        virtual void OnJoyAxis(std::shared_ptr<JoyAxisListener> eventListener);

        virtual void OnJoyButtonDown(std::shared_ptr<JoyButtonListener> eventListener);

        virtual void OnJoyButtonUp(std::shared_ptr<JoyButtonListener> eventListener);

        virtual void OnJoyHat(std::shared_ptr<JoyHatListener> eventListener);

        virtual void OnJoyBall(std::shared_ptr<JoyBallListener> eventListener);

        virtual void OnMinimize(std::shared_ptr<EventListener> eventListener);

        virtual void OnRestore(std::shared_ptr<EventListener> eventListener);

        virtual void OnResize(std::shared_ptr<WindowResizeListener> eventListener);

        virtual void OnExpose(std::shared_ptr<EventListener> eventListener);

        virtual void OnExit(std::shared_ptr<EventListener> eventListener);

        virtual void OnUser(std::shared_ptr<UserListener> eventListener);

        bool poll();

        void process();

    protected:
        std::vector<std::shared_ptr<EventListener>> _InputFocusEvents;
        std::vector<std::shared_ptr<EventListener>> _InputBlurEvents;
        std::vector<std::shared_ptr<EventListener>> _MouseFocusEvents;
        std::vector<std::shared_ptr<EventListener>> _MouseBlurEvents;
        std::vector<std::shared_ptr<EventListener>> _MinimizeEvents;
        std::vector<std::shared_ptr<EventListener>> _RestoreEvents;
        std::vector<std::shared_ptr<EventListener>> _ExposeEvents;
        std::vector<std::shared_ptr<EventListener>> _ExitEvents;

        std::vector<std::shared_ptr<UserListener>> _UserEvents;

        std::vector<std::shared_ptr<WindowResizeListener>> _WindowResizeEvents;

        std::vector<std::shared_ptr<JoyBallListener>> _JoyBallEvents;

        std::vector<std::shared_ptr<JoyHatListener>> _JoyHatEvents;

        std::vector<std::shared_ptr<JoyButtonListener>> _JoyButtonDownEvents;
        std::vector<std::shared_ptr<JoyButtonListener>> _JoyButtonUpEvents;

        std::vector<std::shared_ptr<JoyAxisListener>> _JoyAxisEvents;

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

//        std::vector<std::shared_ptr<EventListener>> _onUpdate;
//        std::vector<std::shared_ptr<

        Event event;
    };
}

#endif //TEDM_EVENTHANDLER_H
