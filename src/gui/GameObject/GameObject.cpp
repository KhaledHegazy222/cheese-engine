#include "GameObject.h"

#include "../TextureManager/TextureManager.h"

GameObject::GameObject(const char *texturesheet, SDL_Rect _srcRect,
                       SDL_Rect _desRect) {
    objTexture = TextureManager::LoadTexture(texturesheet);
    srcRect = _srcRect;
    desRect = _desRect;
}
GameObject::~GameObject() {}

void GameObject::Update(int x_des, int y_des) {
    desRect.x = x_des;
    desRect.y = y_des;
}

void GameObject::Render() {
    TextureManager::Draw(objTexture, srcRect, desRect);
}