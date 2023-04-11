#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <SDL_image.h>

#include <filesystem>
#include <iostream>

using namespace std;

extern string CHEESE_ENGINE;

#define WIDTH 800
#define HIGHT 640
#define aspectRatio (16.0 / 9.0)
#define FPS 60
#define frameDelay 1000 / FPS

#define GET(PATH) string(CHEESE_ENGINE + "/" + PATH).c_str()   // Get relative path despite of the place of running the project

class Game {
   public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    void handleFPS();
    bool running() { return isRunning; }
    static int getPos(float p, bool isY);

    static SDL_Renderer *renderer;
    static SDL_Window *window;
    static int w, h;

   private:
    bool isRunning;
};

#endif