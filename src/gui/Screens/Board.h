#pragma once

#include <SDL_ttf.h>
#include <gui/Game.h>

#include "../TextRenderer/TextRenderer.h"

class chessBoard {
   public:
    chessBoard();
    ~chessBoard();
    void Render();
    bool isReversed;
    int squareLength, xStart, yStart;
    bool validClick(int posX, int posY);
    std::pair<int, int> clickToCell(int posX, int posY);
    pair<int, int> selectedCell;

   private:
    SDL_Texture *imageBoard;
    SDL_Texture *wPawn;
    SDL_Texture *wKnight;
    SDL_Texture *wBishop;
    SDL_Texture *wRock;
    SDL_Texture *wQueen;
    SDL_Texture *wKing;
    SDL_Texture *bPawn;
    SDL_Texture *bKnight;
    SDL_Texture *bBishop;
    SDL_Texture *bRock;
    SDL_Texture *bQueen;
    SDL_Texture *bKing;
    Text *numRow[8];
    Text *numCol[8];
};