#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <filesystem>

using namespace std;

extern string CHEESE_ENGINE;

#define WIDTH      800
#define HIGHT      640
#define FPS        60
#define frameDelay 1000 / FPS

#define GET(PATH) string(CHEESE_ENGINE + "/" + PATH).c_str() // Get relative path despite of the place of running the project


class Game {

    public:
        Game();
        ~Game();
        
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        void handleFPS();
        bool running() {return isRunning;}

        static SDL_Renderer *renderer;

    private:
        bool isRunning;
        SDL_Window *window;

};

#endif