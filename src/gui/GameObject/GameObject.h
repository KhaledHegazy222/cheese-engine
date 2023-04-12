#pragma once

#include <gui/Game.h>

class GameObject {

  public:
    GameObject(const char *texturesheet, SDL_Rect srcRect, SDL_Rect desRect);
    ~GameObject();
    void Update(int x, int y);
    void Render();

  private:
    SDL_Texture *objTexture;
    SDL_Rect srcRect, desRect;
};