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
                default: {
                    //Ignore
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
                default: {
                    //Ignore
                }
            }
            break;
        }

        case SDL_QUIT: {
            std::for_each(_ExitEvents.begin(), _ExitEvents.end(), [&](std::shared_ptr<EventListener> listener) { (*listener)(); } );
            break;
        }

        default: {
            //Ignore
            break;
        }
    }
}

void Tedm::EventHandler::checkListeners() {
    while(event.poll())
        process();

    std::for_each(_eventTriggers.begin(), _eventTriggers.end(), [&](const std::shared_ptr<EventTrigger> &eventTrigger) {
        if(eventTrigger->triggered())
            (*eventTrigger)();
    });
}

void Tedm::EventHandler::addTrigger(std::shared_ptr<Tedm::EventTrigger> trigger) {
    _eventTriggers.push_back(trigger);
}

void Tedm::EventHandler::removeTrigger(std::shared_ptr<Tedm::EventTrigger> trigger) {
    _eventTriggers.erase(std::remove(_eventTriggers.begin(), _eventTriggers.end(), trigger));
}