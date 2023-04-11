#include "TextRenderer.h"

#include <gui/Game.h>

Text::Text(const char* fontFile, int fontSize, const char* text, SDL_Color color) {
    TTF_Font* font = TTF_OpenFont(GET(fontFile), fontSize);
    if (font == NULL) {
        cerr << "Font NOT LOADDED CORRECTLY" << endl;
        assert(font != NULL);
        return;
    }
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, color);
    this->destRect.w = surfaceMessage->w;
    this->destRect.h = surfaceMessage->h;
    this->tex = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(font);
}

Text::Text(int fontSize, const char* text, SDL_Color color) {
    TTF_Font* font = TTF_OpenFont(GET("src/gui/assets/fonts/Arial-bold.ttf"), fontSize);
    if (font == NULL) {
        cerr << "Global Font NOT LOADDED CORRECTLY" << endl;
        assert(font != NULL);
        return;
    }
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, color);
    this->destRect.w = surfaceMessage->w;
    this->destRect.h = surfaceMessage->h;
    this->tex = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(font);
}

Text::~Text() {
    SDL_DestroyTexture(this->tex);
}

void Text::render(int x, int y) {
    this->destRect.x = x;
    this->destRect.y = y;
    SDL_RenderCopy(Game::renderer, this->tex, NULL, &this->destRect);
}
