#include <object/State.h>
#include <object/Object.h>
#include "Game.h"
#include <memory>

class GameState : public State {
	public:

	Object blaster;

	GameState(Game &game) : 
		State(game, "Start"), blaster{graphics, "../resources/blaster.png", 0, 0} {}

	bool init() override { return true; }
	void destroy() override {}
	void paused() override {}
	void resumed() override {}
	void update() override {}
	void render override {
		blaster.draw();
	}
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