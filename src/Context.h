//
// Created by david on 4/27/17.
//

#ifndef TEDM_CONTEXT_H
#define TEDM_CONTEXT_H

#include <string>

namespace Tedm {
    class Context {
    public:
        int width;
        int height;
        std::string windowTitle;
        bool isRunning;
        int timeSinceLastLoop;
        long targetFramerate;
        bool isPaused;
    };
}

#endif //TEDM_CONTEXT_H
