#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;


class Game
{

    SDL_Window *window;

    bool isRunning;

public:
    Game();
    ~Game();
    void init();
    void run();
    void update();
    void render();
    void handleEvents();
    void cleanup();

    static SDL_Renderer *renderer;
    static TTF_Font *font;

    
};
