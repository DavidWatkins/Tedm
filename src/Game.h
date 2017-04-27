//
// Created by david on 4/27/17.
//

#ifndef TEDM_GAME_H
#define TEDM_GAME_H

#include <objects/Surface.h>
#include <events/EventHandler.h>
#include <bits/unordered_map.h>
#include "Context.h"
#include "State.h"

namespace Tedm {

    class Game {
    public:
        Game();
        Game(Context ctx);
        virtual ~Game();

        void start();

        void setTargetFramerate();

        void setWindowTitle();

        void setEventHandler();

        void shutdown();

        void registerState(std::string id, State s);

    protected:

        virtual bool init();

        virtual void destroy();

        virtual void pause();

        virtual void resume();

        virtual bool onInit() = 0;

        virtual void onUpdate() = 0;

        virtual void onRender() = 0;

        virtual void onDestroy() = 0;

        Surface rootSurface;
        EventHandler eventHandler;
        Context ctx;
        std::unordered_map<std::string, State> state_id_dict;
        std::vector<State> states;

        Graphics g;

    private:
        void handleEvent(Event e);
    };

}

#endif //TEDM_GAME_H
