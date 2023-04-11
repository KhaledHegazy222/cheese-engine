#include <gui/game.h>
#include "../../textureManager/textureManager.h"
class HomeScreen
{

public:
    static void init();
    static void render();
    static void handleClicks(int, int);
};

class Button
{
    int width, height, posX, posY;

public:
    const char *text;
    void init(int, int, int, int, const char *);
    void render();
    bool isClicked(int, int);
};