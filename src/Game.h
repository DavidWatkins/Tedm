//
//

#ifndef TEDM_GAME_H
#define TEDM_GAME_H

namespace Tedm {
    class Game;
}

#include <unordered_map>
#include "events/EventHandler.h"
#include "utils/Logger.h"
#include "objects/object.h"
#include "Context.h"
#include "State.h"
#include "Graphics.h"
#include "utils/Timer.h"

namespace Tedm {

    class Game {
    public:
        Game();
        Game(Context ctx);
        virtual ~Game();

        void mainLoop();

        void setTargetFramerate(int framerate);

        void setWindowTitle(std::string windowTitle);

        void shutdown();

        void registerState(std::string id, std::shared_ptr<State> s);

        void transition(std::string newStateId);

    protected:

        virtual bool init();

        virtual void destroy();

        virtual void pause();

        virtual void resume();

        EventHandler eventHandler;
        Context ctx;
        std::unordered_map<std::string, std::shared_ptr<State>> state_id_dict;
        std::string currentStateId;
        std::string startStateId;

        Logger log;
        Graphics graphics;

        std::string nextStateId;
        bool doTransition;
    };

}

#endif //TEDM_GAME_H
