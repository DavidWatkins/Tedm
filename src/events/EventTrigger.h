//
// Created by david on 4/27/17.
//

#ifndef TEDM_EVENTTRIGGER_H
#define TEDM_EVENTTRIGGER_H

namespace Tedm {
    class EventTrigger {
    public:
        virtual bool triggered() = 0;
        virtual void operator()() = 0;
    };
}

#endif //TEDM_EVENTTRIGGER_H
