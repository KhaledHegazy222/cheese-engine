#include "PlayScreen.h"

#include "../../GameObject/GameObject.h"
#include "../Board.h"
#include <board/board.h>
#include <gui/Game.h>

chessBoard *board = nullptr;
GameObject *Background;
extern Board *boardRepresentation;

void PlayScreen::init() {
    board = new chessBoard();
    Background = new GameObject("src/gui/assets/Background.jpg",
                                SDL_Rect{0, 0, 2500, 1600},
                                SDL_Rect{0, 0, Game::w, Game::h});
}
void PlayScreen::cleanUp() {
    delete board;
    delete Background;
}
void PlayScreen::update() {}
void PlayScreen::handleEvents(SDL_Event *event) {
    switch (event->type) {
    case SDL_MOUSEBUTTONDOWN: {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        PlayScreen::handleClicks(mouseX, mouseY);
        break;
    }
    default:
        break;
    }
}
inline void statusEngine() {
    SDL_Rect Rect;
    SDL_SetRenderDrawColor(Game::renderer, 255, 150, 0, 128); // Red color
    Rect = {5, Game::getPos(0.70, 1), Game::getPos(0.18, 0) - 5, Game::h - 10};
    SDL_RenderFillRect(Game::renderer, &Rect);
}
void PlayScreen::render() {
    SDL_Rect Rect;
    SDL_SetRenderDrawBlendMode(Game::renderer, SDL_BLENDMODE_BLEND);
    Background->Render();
    statusEngine();
    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 128); // Red color
    Rect = {Game::w - Game::getPos(0.29, 0) - 5, 5, Game::getPos(0.29, 0) - 5,
            Game::h - 10};
    SDL_RenderFillRect(Game::renderer, &Rect);
    board->Render();
}

void PlayScreen::handleClicks(int mouseX, int mouseY) {
    if (board->validClick(mouseX, mouseY)) {
        std::pair<int, int> chessCell = board->clickToCell(mouseX, mouseY);
        if (board->selectedCell == std::make_pair(-1, -1)) {
            board->selectedCell = chessCell;
            std::cout << board->selectedCell.first << " "
                      << board->selectedCell.second << std::endl;
        } else if (board->selectedCell != chessCell) {
            boardRepresentation->move(board->selectedCell.first,
                                      board->selectedCell.second,
                                      chessCell.first, chessCell.second);
            board->selectedCell = std::make_pair(-1, -1);

            std::cout << chessCell.first << " " << chessCell.second
                      << std::endl;
        }
    }
}