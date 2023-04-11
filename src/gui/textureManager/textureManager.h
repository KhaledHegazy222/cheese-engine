#pragma once

#include <gui/game.h>

class TextureManager
{
public:
    static SDL_Texture *loadTexture(const char *imagePath);
    static void drawTexture(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);
};
