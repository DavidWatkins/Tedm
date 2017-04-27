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

        Context() : timeSinceLastLoop{0}, isRunning{false}, 
                    targetFramerate{10}, isPaused{false}, 
                    width{800}, height{600} {
        }
        
        Context(int w, int h) : timeSinceLastLoop{0}, isRunning{false}, 
                                targetFramerate{10}, isPaused{false}, 
                                width{w}, height{h} {
        }
    };
}

#endif //TEDM_CONTEXT_H
