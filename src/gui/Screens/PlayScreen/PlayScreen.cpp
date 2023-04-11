#include "PlayScreen.h"

#include <gui/Game.h>

#include "../../GameObject/GameObject.h"
#include "../Board.h"

chessBoard* board = nullptr;
GameObject* Background;
void PlayScreen::init() {
    board = new chessBoard();
    Background = new GameObject("src/gui/assets/Background.jpg", SDL_Rect{0, 0, 2500, 1600}, SDL_Rect{0, 0, Game::w, Game::h});
}
void PlayScreen::cleanUp() {
    delete board;
    delete Background;
}
void PlayScreen::update() {
}
void PlayScreen::handleEvents(SDL_Event* Event) {
}
inline void statusEngine() {
    SDL_Rect Rect;
    SDL_SetRenderDrawColor(Game::renderer, 255, 150, 0, 128);   // Red color
    Rect = {5, Game::getPos(0.70, 1), Game::getPos(0.18, 0) - 5, Game::h - 10};
    SDL_RenderFillRect(Game::renderer, &Rect);
}
void PlayScreen::render() {
    SDL_Rect Rect;
    SDL_SetRenderDrawBlendMode(Game::renderer, SDL_BLENDMODE_BLEND);
    Background->Render();
    statusEngine();
    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 128);   // Red color
    Rect = {Game::w - Game::getPos(0.29, 0) - 5, 5, Game::getPos(0.29, 0) - 5, Game::h - 10};
    SDL_RenderFillRect(Game::renderer, &Rect);
    board->Render();
}