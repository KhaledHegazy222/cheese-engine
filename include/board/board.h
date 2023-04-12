#pragma once
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

enum class Piece { None, King, Pawn, Knight, Bishop, Rock, Queen };

enum class Color {
    Black,
    White,
};

enum class Side {
    King,
    Queen,
};

class Board {
    // represent every square state in the board as 4-bit
    // so every row represented as unsigned integer
    unsigned int board[8];
    // notCastledYet[Color][Side]
    bool notCastledYet[2][2];
    Color activeColor;
    // possibleEnPassantTarget = {-1, -1} in case no target otherwise {x, y}
    std::pair<int, int> possibleEnPassantTarget;
    // how many moves both players have made since the last pawn advance or
    // piece capture if it equal to 100 that informs that game is draw
    int numberOfHalfMoves;
    // number of completed turns in the game
    // incremented by one every time black moves
    int numberOfFullMoves;

    // helper functions
    void removePieceFrom(const int, const int);
    void setPieceInto(const int, const int, const Piece, const Color);
    void resolveBoardFen(const std::string &);
    bool isValidFEN(const std::string &);

  public:
    Board();
    // throw error if the given FEN is invalid
    Board(const std::string);
    std::pair<Piece, Color> getSquareState(const int, const int);
    // throw error if the given squares positions is invalid
    void move(const int, const int, const int, const int);
};
