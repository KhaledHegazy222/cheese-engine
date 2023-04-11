#include <gui/Game.h>
#include <SDL_ttf.h>

string CHEESE_ENGINE = filesystem::path(__FILE__).parent_path().parent_path().parent_path().string(); // CHEESE-ENGINE Home Directory Path


SDL_Renderer* Game::renderer = nullptr;
SDL_Window* Game::window = nullptr;
int Game::h;
int Game::w;

Game::Game(){

}
Game::~Game(){

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = ((fullscreen) ? SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_RESIZABLE);
    isRunning = 0; // It will be True if Game is intialized Successfully.!

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            renderer = SDL_CreateRenderer(window, -1, 0);
            if(renderer){
                TTF_Init();
                SDL_GetWindowSize(Game::window, &Game::w, &Game::h);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                isRunning = 1; // Game Intialized Successfully.!
            }else{
                cerr << "Renderer creation failed: " << SDL_GetError() << endl;
            }
        }else{
            cerr << "Window creation failed: " << SDL_GetError() << endl;
        }
    }else{
        cerr << "SDL Video initialization failed: " << SDL_GetError() << endl;
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
void Game::handleFPS(){
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
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
    return;
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return;
}

int Game::getPos(float p, bool isY){ // 20% -> p = 0.20, for X coordinates isY = 0 and for X coordinates isY = 1
    return p * ((isY) ? Game::h : Game::w);
}