#include "include/GameObject.h"
#include "include/TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x_src, int y_src, int h_src, int w_src, int x_des, int y_des, int h_des, int w_des){
    objTexture = TextureManager::LoadTexture(texturesheet);
    srcRect.x = x_src;
    srcRect.y = y_src;
    srcRect.h = h_src;
    srcRect.w = w_src;
    desRect.x = x_des;
    desRect.y = y_des;
    desRect.h = h_des;
    desRect.w = w_des;
}


void GameObject::Update(int x_des, int y_des){
    desRect.x = x_des;
    desRect.y = y_des;
}

void GameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &desRect);
}