#pragma once

#include <gui/Game.h>

class TextureManager {
   public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point* center, SDL_RendererFlip flip);

   private:
};