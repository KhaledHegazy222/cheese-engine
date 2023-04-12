#pragma once

#include <gui/Game.h>

class PlayScreen {
  public:
    static void init();
    static void render();
    static void update();
    static void cleanUp();
    static void handleEvents(SDL_Event *);

  private:
    static void handleClicks(int, int);
    static int paddingX, paddingY;
    static int w, h;
};