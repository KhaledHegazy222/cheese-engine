#include <SDL_ttf.h>

#include "../../TextureManager/TextureManager.h"

class HomeScreen {
  private:
    static void handleClicks(int, int);

  public:
    static TTF_Font *font;
    static void init();
    static void render();
    static void update();
    static void handleEvents(SDL_Event *);
    static void cleanUp();
};

class Button {
    int width, height, posX, posY;

  public:
    const char *text;
    void init(int, int, int, int, const char *);
    void render();
    bool isClicked(int, int);
};