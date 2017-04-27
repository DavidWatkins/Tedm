//
//

#include "EventHandler.h"

void Tedm::EventHandler::process() {
    switch(event.getType()) {

        case SDL_KEYDOWN: {
            std::for_each(_KeyDownEvents.begin(), _KeyDownEvents.end(), [&](std::shared_ptr<KeyEventListener> listener) { (*listener)( event.getKeySymbol() ); } );
            break;
        }

        case SDL_KEYUP: {
            std::for_each(_KeyUpEvents.begin(), _KeyUpEvents.end(), [&](std::shared_ptr<KeyEventListener> listener) { (*listener)( event.getKeySymbol() ); } );
            break;
        }

        case SDL_MOUSEMOTION: {
            std::for_each(_MouseMoveEvents.begin(), _MouseMoveEvents.end(), [&](std::shared_ptr<MouseMoveListener> listener) {
                (*listener)( event.getMouseX(), event.getMouseY(), event.getMouseXRel(), event.getMouseYRel(),
                          event.leftButtonPress(), event.rightButtonPress(), event.middleButtonPress() );
            } );
            break;
        }

        case SDL_MOUSEBUTTONDOWN: {
            switch(event.currentMouseButtonPress()) {
                case SDL_BUTTON_LEFT: {
                    std::for_each(_LButtonDownEvents.begin(), _LButtonDownEvents.end(), [&](std::shared_ptr<MouseButtonListener> listener) {
                        (*listener)( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    std::for_each(_RButtonDownEvents.begin(), _RButtonDownEvents.end(), [&](std::shared_ptr<MouseButtonListener> listener) {
                        (*listener)( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    std::for_each(_MButtonDownEvents.begin(), _MButtonDownEvents.end(), [&](std::shared_ptr<MouseButtonListener> listener) {
                        (*listener)( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
            }
            break;
        }

        case SDL_MOUSEBUTTONUP:    {
            switch(event.currentMouseButtonPress()) {
                case SDL_BUTTON_LEFT: {
                    std::for_each(_LButtonUpEvents.begin(), _LButtonUpEvents.end(), [&](std::shared_ptr<MouseButtonListener> listener) {
                        (*listener)( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    std::for_each(_RButtonUpEvents.begin(), _RButtonUpEvents.end(), [&](std::shared_ptr<MouseButtonListener> listener) {
                        (*listener)( event.currentMouseButtonX(), event.currentMouseButtonY() );
                    } );
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    std::for_each(_MButtonUpEvents.begin(), _MButtonUpEvents.end(), [&](std::shared_ptr<MouseButtonListener> listener) {
                        (*listener)( event.currentMouseButtonX(), event.currentMouseButtonY() );
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
            std::for_each(_ExitEvents.begin(), _ExitEvents.end(), [&](std::shared_ptr<EventListener> listener) { (*listener)(); } );
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

void Tedm::EventHandler::OnInputFocus(std::shared_ptr<Tedm::EventListener> eventListener) {
    _InputFocusEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnInputBlur(std::shared_ptr<Tedm::EventListener> eventListener) {
    _InputBlurEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnKeyDown(std::shared_ptr<Tedm::KeyEventListener> eventListener) {
    _KeyDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnKeyUp(std::shared_ptr<Tedm::KeyEventListener> eventListener) {
    _KeyUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMouseFocus(std::shared_ptr<Tedm::EventListener> eventListener) {
    _MouseFocusEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMouseBlur(std::shared_ptr<Tedm::EventListener> eventListener) {
    _MouseBlurEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMouseMove(std::shared_ptr<Tedm::MouseMoveListener> eventListener) {
    _MouseMoveEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMouseWheel(std::shared_ptr<Tedm::MouseWheelListener> eventListener) {
    _MouseWheelEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnLButtonDown(std::shared_ptr<Tedm::MouseButtonListener> eventListener) {
    _LButtonDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnLButtonUp(std::shared_ptr<Tedm::MouseButtonListener> eventListener) {
    _LButtonUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnRButtonDown(std::shared_ptr<Tedm::MouseButtonListener> eventListener) {
    _RButtonDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnRButtonUp(std::shared_ptr<Tedm::MouseButtonListener> eventListener) {
    _RButtonUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMButtonDown(std::shared_ptr<Tedm::MouseButtonListener> eventListener) {
    _MButtonDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMButtonUp(std::shared_ptr<Tedm::MouseButtonListener> eventListener) {
    _MButtonUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyAxis(std::shared_ptr<Tedm::JoyAxisListener> eventListener) {
    _JoyAxisEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyButtonDown(std::shared_ptr<Tedm::JoyButtonListener> eventListener) {
    _JoyButtonDownEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyButtonUp(std::shared_ptr<Tedm::JoyButtonListener> eventListener) {
    _JoyButtonUpEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyHat(std::shared_ptr<Tedm::JoyHatListener> eventListener) {
    _JoyHatEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnJoyBall(std::shared_ptr<Tedm::JoyBallListener> eventListener) {
    _JoyBallEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnMinimize(std::shared_ptr<Tedm::EventListener> eventListener) {
    _MinimizeEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnRestore(std::shared_ptr<Tedm::EventListener> eventListener) {
    _RestoreEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnResize(std::shared_ptr<Tedm::WindowResizeListener> eventListener) {
    _WindowResizeEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnExpose(std::shared_ptr<Tedm::EventListener> eventListener) {
    _ExposeEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnExit(std::shared_ptr<Tedm::EventListener> eventListener) {
    _ExitEvents.push_back(eventListener);
}

void Tedm::EventHandler::OnUser(std::shared_ptr<Tedm::UserListener> eventListener) {
    _UserEvents.push_back(eventListener);
}

bool Tedm::EventHandler::poll() {
    return event.poll();
}
