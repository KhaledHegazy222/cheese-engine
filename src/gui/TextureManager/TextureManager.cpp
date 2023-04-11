#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName) {
    SDL_Surface* tmpSurface = IMG_Load(GET(fileName));
    if (!tmpSurface) {
        cout << "Failed to load image: " << IMG_GetError() << endl;
        return nullptr;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}