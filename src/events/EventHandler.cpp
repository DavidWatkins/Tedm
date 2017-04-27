//
//

#include "EventHandler.h"

void Tedm::EventHandler::OnEvent(Tedm::Event event) {
    switch(event.getType()) {

        case SDL_KEYDOWN: {
            std::for_each(_KeyDownEvents.begin(), _KeyDownEvents.end(), [](KeyEventListener &listener) { listener( event.getKeySymbol() ); } );
            break;
        }

        case SDL_KEYUP: {
            std::for_each(_KeyUpEvents.begin(), _KeyUpEvents.end(), [](KeyEventListener &listener) { listener( event.getKeySymbol() ); } );
            break;
        }

        case SDL_MOUSEMOTION: {
            std::for_each(_MouseMoveEvents.begin(), _MouseMoveEvents.end(), [](MouseMoveListener &listener) {
                listener( event.getMouseX(), event.getMouseY(), event.getMouseXRel(), event.getMouseYRel(),
                          event.leftButtonPress(), event.rightButtonPress(), event.middleButtonPress() );
            } );
            break;
        }

        case SDL_MOUSEBUTTONDOWN: {
            switch(event.currentMouseButtonPress()) {
                case SDL_BUTTON_LEFT: {
                    std::for_each(_LButtonDownEvents.begin(), _LButtonDownEvents.end(), [](MouseButtonListener &listener) {
                        listener( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    std::for_each(_RButtonDownEvents.begin(), _RButtonDownEvents.end(), [](MouseButtonListener &listener) {
                        listener( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    std::for_each(_MButtonDownEvents.begin(), _MButtonDownEvents.end(), [](MouseButtonListener &listener) {
                        listener( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
            }
            break;
        }

        case SDL_MOUSEBUTTONUP:    {
            switch(event.currentMouseButtonPress()) {
                case SDL_BUTTON_LEFT: {
                    std::for_each(_LButtonUpEvents.begin(), _LButtonUpEvents.end(), [](MouseButtonListener &listener) {
                        listener( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    std::for_each(_RButtonUpEvents.begin(), _RButtonUpEvents.end(), [](MouseButtonListener &listener) {
                        listener( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    std::for_each(_MButtonUpEvents.begin(), _MButtonUpEvents.end(), [](MouseButtonListener &listener) {
                        listener( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
            }
            break;
        }

        case SDL_JOYAXISMOTION: {
            //Ignore
            break;
        }

        case SDL_JOYBALLMOTION: {
            //Ignore
            break;
        }

        case SDL_JOYHATMOTION: {
            //Ignore
            break;
        }
        case SDL_JOYBUTTONDOWN: {
            //Ignore
            break;
        }

        case SDL_JOYBUTTONUP: {
            //Ignore
            break;
        }

        case SDL_QUIT: {
            std::for_each(_ExitEvents.begin(), _ExitEvents.end(), [](EventListener &listener) { listener(); } );
            break;
        }

        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }

        default: {
            //Ignore
            break;
        }
    }
}

void Tedm::EventHandler::OnInputFocus(Tedm::EventListener eventListener) {
    _InputFocusEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnInputBlur(Tedm::EventListener eventListener) {
    _InputBlurEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnKeyDown(Tedm::KeyEventListener eventListener) {
    _KeyDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnKeyUp(Tedm::KeyEventListener eventListener) {
    _KeyUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMouseFocus(Tedm::EventListener eventListener) {
    _MouseFocusEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMouseBlur(Tedm::EventListener eventListener) {
    _MouseBlurEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMouseMove(Tedm::MouseMoveListener eventListener) {
    _MouseMoveEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMouseWheel(Tedm::MouseWheelListener eventListener) {
    _MouseWheelEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnLButtonDown(Tedm::MouseButtonListener eventListener) {
    _LButtonDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnLButtonUp(Tedm::MouseButtonListener eventListener) {
    _LButtonUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnRButtonDown(Tedm::MouseButtonListener eventListener) {
    _RButtonDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnRButtonUp(Tedm::MouseButtonListener eventListener) {
    _RButtonUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMButtonDown(Tedm::MouseButtonListener eventListener) {
    _MButtonDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMButtonUp(Tedm::MouseButtonListener eventListener) {
    _MButtonUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyAxis(Tedm::JoyAxisListener eventListener) {
    _JoyAxisEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyButtonDown(Tedm::JoyButtonListener eventListener) {
    _JoyButtonDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyButtonUp(Tedm::JoyButtonListener eventListener) {
    _JoyButtonUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyHat(Tedm::JoyHatListener eventListener) {
    _JoyHatEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyBall(Tedm::JoyBallListener eventListener) {
    _JoyBallEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMinimize(Tedm::EventListener eventListener) {
    _MinimizeEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnRestore(Tedm::EventListener eventListener) {
    _RestoreEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnResize(Tedm::WindowResizeListener eventListener) {
    _WindowResizeEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnExpose(Tedm::EventListener eventListener) {
    _ExposeEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnExit(Tedm::EventListener eventListener) {
    _ExitEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnUser(Tedm::UserListener eventListener) {
    _UserEvents.push_back(eventListener);
}
