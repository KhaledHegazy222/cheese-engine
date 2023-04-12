#include "Board.h"

#include <SDL_ttf.h>
#include <board/board.h>

#include "../TextureManager/TextureManager.h"

Board *boardRepresentation;

SDL_Color a1 = {75, 115, 153}, a2 = {234, 233, 210};
SDL_Rect _srcRect;
SDL_Rect _destRect;

chessBoard::chessBoard() {
    boardRepresentation =
        new Board("3R4/1pk3pp/pBp5/8/4P3/1Q5P/PP2qrP1/1K6 b - - 7 31");
    this->squareLength = Game::getPos(0.48, 0) / 8;
    this->xStart = Game::getPos(0.22, 0);
    this->yStart = (Game::h + Game::getPos(0.48, 0)) / 2 - squareLength;
    {
        imageBoard = TextureManager::LoadTexture("src/gui/assets/Board.png");
        _srcRect = {0, 0, 1200, 1200};
        _destRect = {Game::getPos(0.22, 0),
                     (Game::h - Game::getPos(0.48, 0)) / 2,
                     Game::getPos(0.48, 0), Game::getPos(0.48, 0)};

        wPawn = TextureManager::LoadTexture("src/gui/assets/wp.png");
        bPawn = TextureManager::LoadTexture("src/gui/assets/bp.png");

        wRock = TextureManager::LoadTexture("src/gui/assets/wr.png");
        bRock = TextureManager::LoadTexture("src/gui/assets/br.png");

        wKnight = TextureManager::LoadTexture("src/gui/assets/wn.png");
        bKnight = TextureManager::LoadTexture("src/gui/assets/bn.png");

        wBishop = TextureManager::LoadTexture("src/gui/assets/wb.png");
        bBishop = TextureManager::LoadTexture("src/gui/assets/bb.png");

        wKing = TextureManager::LoadTexture("src/gui/assets/wk.png");
        bKing = TextureManager::LoadTexture("src/gui/assets/bk.png");

        wQueen = TextureManager::LoadTexture("src/gui/assets/wq.png");
        bQueen = TextureManager::LoadTexture("src/gui/assets/bq.png");
    }
    isReversed = 1;
    if (isReversed)
        swap(a1, a2);
    {
        for (int row = 0; row < 8; ++row) {
            numRow[row] = new Text(24, string(1, '1' + row).c_str(), ((row % 2) ? a1 : a2));
        }
        for (int col = 0; col < 8; ++col) {
            numCol[col] = new Text(24, string(1, 'a' + col).c_str(), ((col % 2) ? a1 : a2));
        }
    }
}
chessBoard::~chessBoard() {
    {
        SDL_DestroyTexture(imageBoard);

        SDL_DestroyTexture(wPawn);
        SDL_DestroyTexture(bPawn);

        SDL_DestroyTexture(wRock);
        SDL_DestroyTexture(bRock);

        SDL_DestroyTexture(wKnight);
        SDL_DestroyTexture(bKnight);

        SDL_DestroyTexture(wBishop);
        SDL_DestroyTexture(bBishop);

        SDL_DestroyTexture(wQueen);
        SDL_DestroyTexture(bQueen);

        SDL_DestroyTexture(wKing);
        SDL_DestroyTexture(bKing);
    }
    {
        for (int i = 0; i < 8; ++i) {
            delete numRow[i];
            delete numCol[i];
        }
    }
}

void chessBoard::Render() {
    // Draw Board
    TextureManager::Draw(this->imageBoard, {0, 0, 1200, 1200}, {Game::getPos(0.22, 0), (Game::h - Game::getPos(0.48, 0)) / 2, Game::getPos(0.48, 0), Game::getPos(0.48, 0)});

    // Numering the Board
    {
        for (int row = 0; row < 8; ++row) {
            if (isReversed) {
                numRow[7 - row]->render(xStart + 3,
                                        yStart - row * squareLength + 3);
            } else {
                numRow[row]->render(xStart + 3,
                                    yStart - row * squareLength + 3);
            }
        }
        for (int col = 0; col < 8; ++col) {
            if (isReversed) {
                numCol[7 - col]->render(xStart - 3 + (col + 1) * squareLength - numCol[col]->destRect.w, yStart - 1 + squareLength - numCol[col]->destRect.h);
            } else {
                numCol[col]->render(xStart - 3 + (col + 1) * squareLength - numCol[col]->destRect.w, yStart - 1 + squareLength - numCol[col]->destRect.h);
            }
        }
    }
    // Put pieces of Current State
    {
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                pair<Piece, Color> state =
                    boardRepresentation->getSquareState(col, row);
                SDL_Rect src = {0, 0, 150, 150}, dest;
                if (this->isReversed) {
                    dest = {xStart + (7 - col) * squareLength,
                            yStart - (7 - row) * squareLength, squareLength,
                            squareLength};
                } else {
                    dest = {xStart + col * squareLength,
                            yStart - row * squareLength, squareLength,
                            squareLength};
                }
                switch (state.second) {
                    case Color::White:   // White
                        switch (state.first) {
                            case Piece::Pawn:   // Pawn
                                TextureManager::Draw(this->wPawn, src, dest);
                                break;
                            case Piece::Rock:   // Rock
                                TextureManager::Draw(this->wRock, src, dest);
                                break;
                            case Piece::Knight:   // Knight
                                TextureManager::Draw(this->wKnight, src, dest);
                                break;
                            case Piece::Bishop:   // Bishop
                                TextureManager::Draw(this->wBishop, src, dest);
                                break;
                            case Piece::Queen:   // Queen
                                TextureManager::Draw(this->wQueen, src, dest);
                                break;
                            case Piece::King:   // King
                                TextureManager::Draw(this->wKing, src, dest);
                                break;

                            default:
                                break;
                        }
                        break;
                    case Color::Black:   // Black
                        switch (state.first) {
                            case Piece::Pawn:   // Pawn
                                TextureManager::Draw(this->bPawn, src, dest);
                                break;
                            case Piece::Rock:   // Rock
                                TextureManager::Draw(this->bRock, src, dest);
                                break;
                            case Piece::Knight:   // Knight
                                TextureManager::Draw(this->bKnight, src, dest);
                                break;
                            case Piece::Bishop:   // Bishop
                                TextureManager::Draw(this->bBishop, src, dest);
                                break;
                            case Piece::Queen:   // Queen
                                TextureManager::Draw(this->bQueen, src, dest);
                                break;
                            case Piece::King:   // King
                                TextureManager::Draw(this->bKing, src, dest);
                                break;

                            default:
                                break;
                        }
                        break;
                    default:

                        break;
                }
            }
        }
    }
}

bool chessBoard::validClick(int posX, int posY) {
    int maxX = xStart + 8 * squareLength;
    int maxY = yStart + squareLength;
    int minX = xStart;
    int minY = yStart - 7 * squareLength;
    return posX >= minX && posX <= maxX && posY >= minY && posY <= maxY;
}

std::pair<int, int> chessBoard::clickToCell(int posX, int posY) {
    int minX = xStart;
    int minY = yStart - 7 * squareLength;
    int row = 7 - (posY - minY) / squareLength;
    int column = (posX - minX) / squareLength;
    row = ((isReversed) ? 7 - row : row);
    column = ((isReversed) ? 7 - column : column);
    return std::make_pair(row, column);
}