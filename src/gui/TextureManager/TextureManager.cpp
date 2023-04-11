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
void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_RenderSetIntegerScale(Game::renderer, SDL_TRUE);
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, angle, center, flip);
    SDL_RenderSetIntegerScale(Game::renderer, SDL_FALSE);
}