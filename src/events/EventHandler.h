//
// http://www.sdltutorials.com/sdl-events
//

#ifndef TEDM_EVENTHANDLER_H
#define TEDM_EVENTHANDLER_H

#include <vector>
#include <algorithm>

#include "Event.h"
#include "EventListener.h"

namespace Tedm {
    class EventHandler {
    public:
        virtual void OnEvent(Event event);

        virtual void OnInputFocus(EventListener eventListener);

        virtual void OnInputBlur(EventListener eventListener);

        virtual void OnKeyDown(KeyEventListener eventListener);

        virtual void OnKeyUp(KeyEventListener eventListener);

        virtual void OnMouseFocus(EventListener eventListener);

        virtual void OnMouseBlur(EventListener eventListener);

        virtual void OnMouseMove(MouseMoveListener eventListener);

        virtual void OnMouseWheel(MouseWheelListener eventListener);

        virtual void OnLButtonDown(MouseButtonListener eventListener);

        virtual void OnLButtonUp(MouseButtonListener eventListener);

        virtual void OnRButtonDown(MouseButtonListener eventListener);

        virtual void OnRButtonUp(MouseButtonListener eventListener);

        virtual void OnMButtonDown(MouseButtonListener eventListener);

        virtual void OnMButtonUp(MouseButtonListener eventListener);

        virtual void OnJoyAxis(JoyAxisListener eventListener);

        virtual void OnJoyButtonDown(JoyButtonListener eventListener);

        virtual void OnJoyButtonUp(JoyButtonListener eventListener);

        virtual void OnJoyHat(JoyHatListener eventListener);

        virtual void OnJoyBall(JoyBallListener eventListener);

        virtual void OnMinimize(EventListener eventListener);

        virtual void OnRestore(EventListener eventListener);

        virtual void OnResize(WindowResizeListener eventListener);

        virtual void OnExpose(EventListener eventListener);

        virtual void OnExit(EventListener eventListener);

        virtual void OnUser(UserListener eventListener);

        bool poll();

        void process();

    protected:
        std::vector<EventListener> _InputFocusEvents;
        std::vector<EventListener> _InputBlurEvents;
        std::vector<EventListener> _MouseFocusEvents;
        std::vector<EventListener> _MouseBlurEvents;
        std::vector<EventListener> _MinimizeEvents;
        std::vector<EventListener> _RestoreEvents;
        std::vector<EventListener> _ExposeEvents;
        std::vector<EventListener> _ExitEvents;

        std::vector<UserListener> _UserEvents;

        std::vector<WindowResizeListener> _WindowResizeEvents;

        std::vector<JoyBallListener> _JoyBallEvents;

        std::vector<JoyHatListener> _JoyHatEvents;

        std::vector<JoyButtonListener> _JoyButtonDownEvents;
        std::vector<JoyButtonListener> _JoyButtonUpEvents;

        std::vector<JoyAxisListener> _JoyAxisEvents;

        std::vector<MouseButtonListener> _LButtonDownEvents;
        std::vector<MouseButtonListener> _LButtonUpEvents;
        std::vector<MouseButtonListener> _RButtonDownEvents;
        std::vector<MouseButtonListener> _RButtonUpEvents;
        std::vector<MouseButtonListener> _MButtonDownEvents;
        std::vector<MouseButtonListener> _MButtonUpEvents;

        std::vector<MouseMoveListener> _MouseMoveEvents;

        std::vector<MouseWheelListener> _MouseWheelEvents;

        std::vector<KeyEventListener> _KeyDownEvents;
        std::vector<KeyEventListener> _KeyUpEvents;
    };
}

#endif //TEDM_EVENTHANDLER_H
