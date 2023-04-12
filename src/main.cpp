#include <gui/Game.h>



int main(int argc, char *args[]) {
    long long frameStart;
    int frameTime;

    Game::init("Cheese Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HIGHT, 1);

    while (Game::running()) {
        Game::update();
        Game::render();
        Game::handleFPS();
        Game::handleEvents();
    }

    Game::clean();

    return 0;
}