//
// Created by david on 4/27/17.
//

#ifndef TEDM_EVENTLISTENER_H
#define TEDM_EVENTLISTENER_H

#include <SDL_keycode.h>

namespace Tedm {
    class EventListener {
        public:
        virtual void operator()() = 0;
    };

    class KeyEventListener {
    public:
        virtual void operator()(SDL_Keycode sym) = 0;
    };

    class MouseMoveListener {
        public:
        virtual void operator()(int x, int y, int rel_x, int rel_y,
                                bool left_click, bool right_click, bool middle_click) = 0;
    };

    class MouseWheelListener {
        public:
        virtual void operator()(bool scroll_up, bool scroll_down) = 0;
    };

    class MouseButtonListener {
        public:
        virtual void operator()(int x, int y) = 0;
    };

    class JoyAxisListener {
        public:
        virtual void operator()(int which, int axis, int value) = 0;
    };

    class JoyButtonListener {
        public:
        virtual void operator()(int which, int button) = 0;
    };

    class JoyHatListener {
        public:
        virtual void operator()(int which, int hat, int value) = 0;
    };

    class JoyBallListener {
        public:
        virtual void operator()(int which, int ball, int x_rel, int y_rel) = 0;
    };

    class WindowResizeListener {
        public:
        virtual void operator()(int w, int h) = 0;
    };

    class UserListener {
    public:
        virtual void operator()(int type, int code, void* data1, void* data2) = 0;
    };
}

#endif //TEDM_EVENTLISTENER_H
