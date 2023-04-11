#include "textureManager.h"

SDL_Texture *TextureManager::loadTexture(const char *imagePath)
{
    SDL_Surface *imageSurface = IMG_Load(imagePath);
    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(Game::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    return imageTexture;
}

void TextureManager::drawTexture(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest)
{
    SDL_RenderCopy(Game::renderer, texture, src, dest);
}