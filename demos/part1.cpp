#include <State.h>
#include "Game.h"
#include <memory>

class GameState : public Tedm::State {
public:
	GameState(Tedm::Game &g) : State(g, "GameState") {}

	bool init() override { return true; }
	void destroy() override {}
	void paused() override {}
	void resumed() override {}
	void update() override {}
	void render() override {}
};

int main(int argc, char*argv[]) {
	Tedm::Context context;
    Tedm::Game g = Tedm::Game(context);
    context.width = 800;
    context.height = 600;
    GameState game_state(g);
    g.registerState("Start", std::make_shared<GameState>(game_state));
	g.setStartState("Start");
    g.mainLoop();
}