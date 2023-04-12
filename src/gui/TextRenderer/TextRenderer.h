#pragma once

#include <SDL_ttf.h>

class Text {
  public:
    Text(const char *fontFile, int fontSize, const char *text, SDL_Color color);
    Text(int fontSize, const char *text, SDL_Color color);
    ~Text();
    void render(int x, int y);
    SDL_Rect destRect;

  private:
    SDL_Texture *tex;
};