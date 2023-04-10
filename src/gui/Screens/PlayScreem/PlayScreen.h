#pragma once

#include <gui/Game.h>

class PlayScreen{

    public:
        void Init();
        void Render();
        void Update();   
        

    private:
        int paddingX, paddingY;
        int w, h;
};