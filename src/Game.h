//
//

#ifndef TEDM_GAME_H
#define TEDM_GAME_H

#include <unordered_map>
#include "events/EventHandler.h"
#include "utils/Logger.h"
#include "objects/object.h"
#include "Context.h"
#include "State.h"
#include "Graphics.h"

namespace Tedm {

    class Game {
    public:
        Game();
        Game(Context ctx);
        virtual ~Game();

        void mainLoop();

        void setTargetFramerate(int framerate);

        void setWindowTitle(std::string windowTitle);

        void setEventHandler(EventHandler &eventHandler);

        void shutdown();

        void registerState(std::string id, State s);

        bool collision(Object &obj);

    protected:

        virtual bool init();

        virtual void destroy();

        virtual void pause();

        virtual void resume();

        EventHandler eventHandler;
        Context ctx;
        std::unordered_map<std::string, State> state_id_dict;
        State &currentState;

        //TODO WHy does game need to manage objects?
        std::vector<Object> objects;

        Logger log;
        Graphics graphics;

    };

}

#endif //TEDM_GAME_H
