#include <gui/Game.h>
#include "include/TextureManager.h"
#include "include/GameObject.h"
#include "include/Map.h"

string CHEESE_ENGINE = filesystem::path(__FILE__).parent_path().parent_path().parent_path().string(); // CHEESE-ENGINE Home Directory Path


SDL_Renderer* Game::renderer = nullptr;

Game::Game(){

}
Game::~Game(){

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = ((fullscreen) ? SDL_WINDOW_FULLSCREEN : 0);
    isRunning = 0; // It will be True if Game is intialized Successfully.!

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            renderer = SDL_CreateRenderer(window, -1, 0);
            if(renderer){
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                isRunning = 1; // Game Intialized Successfully.!
            }
            
        }
    }
    
}
void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}
void handleFPS(){
    static long long frameStart = SDL_GetTicks64();
    int frameTime = SDL_GetTicks64() - frameStart;
    if(frameDelay > frameTime){
        SDL_Delay(frameDelay - frameTime);
    }
    frameStart = SDL_GetTicks64(); // Start Calculating from here till next call of 'handleFPS()'
}
void Game::update(){
    
}
void Game::render(){
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
