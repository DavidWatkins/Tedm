#include <object/State.h>
#include "Game.h"
#include <memory>

class GameState : public State {
	bool init() override { return true; }
	void destroy() override {}
	void paused() override {}
	void resumed() override {}
	void update() override {}
	void render override {}
}

int main(int argc, char*argv[]) {
	Context context;
    Game g = Game(context);
    context.width = 800;
    context.height = 600;
    GameState game_state(g);
    g.registerState("Start", make_shared<GameState>(game_state));
    g.mainLoop();
}