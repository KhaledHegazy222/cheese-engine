#pragma once

#include <gui/Game.h>

class GameObject {
    
    public:
        GameObject(const char* texturesheet, int x_src, int y_src, int h_src, int w_src, int x_des, int y_des, int h_des, int w_des);
        ~GameObject();
        void Update(int x, int y);
        void Render();

    private:
        SDL_Texture* objTexture;
        SDL_Rect srcRect, desRect;
        

};