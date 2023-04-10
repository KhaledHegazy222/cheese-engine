#include <gui/game.h>
#include "textureManager.h"
#include "homeScreen/homeScreen.h"
#include <iostream>

enum presentedScreen
{
    HOME_SCREEN,
    PLAY_SCREEN,
    ANALYSIS_SCREEN,
    STATISTICS_SCREEN
};

SDL_Renderer *Game::renderer;
TTF_Font *Game::font;

void handleClicks(int mouseX, int mouseY)
{
    HomeScreen::handleClicks(mouseX, mouseY);
}

Game::Game() {}

Game::~Game() {}

void Game::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
    font = TTF_OpenFont("./src/fonts/open-sans/OpenSans.ttf", 100);
    isRunning = true;

    HomeScreen::init();
}

void Game::run()
{
    while (isRunning)
    {
        handleEvents();
        update();
        render();
    }
    cleanup();
}

void Game::update()
{
}

void Game::render()
{
    SDL_RenderClear(renderer);
    HomeScreen::render();

    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    int mouseX, mouseY;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONUP:
            SDL_GetMouseState(&mouseX, &mouseY);
            handleClicks(mouseX, mouseY);
            break;

        default:
            break;
        }
    }
}

void Game::cleanup()
{

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
