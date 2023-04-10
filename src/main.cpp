#include <gui/Game.h>

Game *game = nullptr;

using namespace std;

int main(int argc, char *args[]) {
    long long frameStart;
    int frameTime;

    game = new Game();
    game->init("Cheese Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HIGHT, 1);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
        game->handleFPS();
    }

    game->clean();

    return 0;
}