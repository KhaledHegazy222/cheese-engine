#include <SDL_ttf.h>
#include <gui/Game.h>

#include "Screens/PlayScreen/PlayScreen.h"
#include "Screens/ScreenHandler/ScreenHandler.h"

string CHEESE_ENGINE = filesystem::path(__FILE__)
                           .parent_path()
                           .parent_path()
                           .parent_path()
                           .string(); // CHEESE-ENGINE Home Directory Path

PlayScreen playScreen;
SDL_Renderer *Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;
bool Game::isRunning;
int Game::h;
int Game::w;

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
    int flags =
        ((fullscreen) ? SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP
                      : SDL_WINDOW_RESIZABLE);
    isRunning = 0; // It will be True if Game is intialized Successfully.!

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {
                TTF_Init();
                SDL_GetWindowSize(Game::window, &Game::w, &Game::h);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                isRunning = 1; // Game Intialized Successfully.!
                initScreen();
            } else {
                cerr << "Renderer creation failed: " << SDL_GetError() << endl;
            }
        } else {
            cerr << "Window creation failed: " << SDL_GetError() << endl;
        }
    } else {
        cerr << "SDL Video initialization failed: " << SDL_GetError() << endl;
    }
}
void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
        isRunning = false;
    else {
        handleEventsScreen(&event);
    }
}
void Game::handleFPS() {
    static long long frameStart = SDL_GetTicks64();
    int frameTime = SDL_GetTicks64() - frameStart;
    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
    frameStart = SDL_GetTicks64(); // Start Calculating from here till next call
                                   // of 'handleFPS()'
}
void Game::update() { updateScreen(); }
void Game::render() {
    SDL_RenderClear(renderer);
    renderScreen();
    SDL_RenderPresent(renderer);
    return;
}
void Game::stopGame() { isRunning = 0; }
void Game::clean() {
    cleanUpScreen();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return;
}

int Game::getPos(float p, bool isY) { // 20% -> p = 0.20, for X coordinates isY
                                      // = 0 and for X coordinates isY = 1
    return p * ((isY) ? Game::h : Game::w);
}