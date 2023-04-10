#include <gui/Game.h>
#include "PlayScreen.h"
#include "../Board.h"
#include "../../GameObject/GameObject.h"

chessBoard* board = nullptr;

void PlayScreen::Init(){
    board = new chessBoard();
}
void PlayScreen::Update(){
    
}

void PlayScreen::Render(){
    SDL_Rect Rect;
    SDL_SetRenderDrawBlendMode(Game::renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 128); // Red color
    Rect = { 5, 5, Game::getPos(0.18, 0) - 5, Game::h - 10 };
    SDL_RenderFillRect(Game::renderer, &Rect);
    Rect = { Game::w - Game::getPos(0.29, 0) - 5, 5, Game::getPos(0.29, 0) - 5, Game::h - 10 };
    SDL_RenderFillRect(Game::renderer, &Rect);
    board->Render();
    
}