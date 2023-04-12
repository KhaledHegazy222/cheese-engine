#include "../../include/board/board.h"

void Board::removePieceFrom(const int column, const int row) {
    if (column < 0 or row < 0 or column > 7 or row > 7)
        throw("Invalid piece position");

    board[row] &= (((~0) << 4) << (4 * column)) | ((1 << (4 * column)) - 1);
}

void Board::setPieceInto(const int column, const int row, const Piece piece,
                         const Color color) {
    if (column < 0 or row < 0 or column > 7 or row > 7)
        throw("Invalid piece position");

    removePieceFrom(column, row);
    int p = static_cast<int>(piece);
    if (color == Color::White)
        p |= (1 << 3);
    board[row] |= (p << (4 * column));
}

void Board::move(const int column0, const int row0, const int column1, const int row1) {
    std::pair<Piece, Color> state = getSquareState(column0, row0);
    removePieceFrom(column0, row0);
    removePieceFrom(column1, row1);
    setPieceInto(column1, row1, state.first, state.second);
}

std::pair<Piece, Color> Board::getSquareState(const int column, const int row) {
    if (column < 0 or row < 0 or column > 7 or row > 7)
        throw("Invalid piece position");

    int state = (board[row] >> (4 * column)) & ((1 << 4) - 1);
    return std::make_pair((Piece)(state & 7), (Color)(state >> 3));
}

Board::Board()
    : Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {}

Board::Board(const std::string fen) {
    if (!isValidFEN(fen))
        throw("The given FEN is not valid.");

    // Initialize variables to hold FEN components
    std::vector<std::string> fenComponents;
    std::stringstream ss(fen);
    std::string component;

    while (std::getline(ss, component, ' ')) {
        fenComponents.push_back(component);
    }

    resolveBoardFen(fenComponents[0]);

    activeColor = (Color)(fenComponents[1] == "w");

    // resolve castling component
    const std::string &castling = fenComponents[2];
    notCastledYet[(int)Color::White][(int)Side::King] =
        (castling.find("K") != std::string::npos);
    notCastledYet[(int)Color::White][(int)Side::Queen] =
        (castling.find("Q") != std::string::npos);
    notCastledYet[(int)Color::Black][(int)Side::King] =
        (castling.find("k") != std::string::npos);
    notCastledYet[(int)Color::Black][(int)Side::Queen] =
        (castling.find("q") != std::string::npos);

    // resolve en passant component
    const std::string &enPassant = fenComponents[3];
    if (enPassant == "-") {
        possibleEnPassantTarget = {-1, -1};
    } else {
        possibleEnPassantTarget = {enPassant[0] - 'a', enPassant[1] - '0'};
    }

    // resolve halfMove clock and fullMove number components
    numberOfHalfMoves = std::stoi(fenComponents[4]);
    numberOfFullMoves = std::stoi(fenComponents[5]);
}

void Board::resolveBoardFen(const std::string &board) {
    int row = 7, column = 0;
    for (const char &c : board) {
        if (c == '/') {
            --row;
            column = 0;
        } else if (isdigit(c)) {
            for (int i = 0; i < c - '0'; ++i) {
                setPieceInto(column++, row, Piece::None, Color::Black);
            }
        } else {
            Color color = (Color)((bool)std::isupper(c));
            switch (c) {
            case 'K':
            case 'k':
                setPieceInto(column, row, Piece::King, color);
                break;
            case 'P':
            case 'p':
                setPieceInto(column, row, Piece::Pawn, color);
                break;
            case 'N':
            case 'n':
                setPieceInto(column, row, Piece::Knight, color);
                break;
            case 'B':
            case 'b':
                setPieceInto(column, row, Piece::Bishop, color);
                break;
            case 'R':
            case 'r':
                setPieceInto(column, row, Piece::Rock, color);
                break;
            case 'Q':
            case 'q':
                setPieceInto(column, row, Piece::Queen, color);
                break;
            }
            ++column;
        }
    }
}

bool Board::isValidFEN(const std::string &fen) {
    // Initialize variables to hold FEN components
    std::vector<std::string> fenComponents;
    std::stringstream ss(fen);
    std::string component;

    while (std::getline(ss, component, ' ')) {
        fenComponents.push_back(component);
    }

    // Check for correct number of FEN components
    if (fenComponents.size() != 6) {
        return false;
    }

    // Check board component for valid format
    const std::string &board = fenComponents[0];
    if (std::count(board.begin(), board.end(), '/') != 7) {
        return false;
    }
    int rankSum = 0;

    for (const char &c : board) {
        if (isdigit(c)) {
            rankSum += (int)(c - '0');
        } else if (c == '/') {
            if (rankSum != 8) {
                return false;
            }
            rankSum = 0;
        } else if (c != 'p' && c != 'P' && c != 'n' && c != 'N' && c != 'b' &&
                   c != 'B' && c != 'r' && c != 'R' && c != 'q' && c != 'Q' &&
                   c != 'k' && c != 'K') {
            return false;
        } else {
            rankSum++;
        }
    }

    if (rankSum != 8) {
        return false;
    }

    // Check active color component for valid value
    const std::string &activeColor = fenComponents[1];
    if (activeColor != "w" && activeColor != "b") {
        return false;
    }

    // Check castling component for valid value
    const std::string &castling = fenComponents[2];
    if (castling == "" or
        (castling != "-" &&
         castling.find_first_not_of("KQkq") != std::string::npos)) {
        return false;
    }

    // Check en passant component for valid value
    const std::string &enPassant = fenComponents[3];
    if (enPassant == "" or
        (enPassant != "-" &&
         (enPassant.length() != 2 || enPassant[0] < 'a' || enPassant[0] > 'h' ||
          enPassant[1] < '1' || enPassant[1] > '8'))) {
        return false;
    }

    // Check halfMove clock and fullMove number components for valid integer
    // values
    try {
        const std::string &halfMoveClock = fenComponents[4];
        const std::string &fullMoveNumber = fenComponents[5];
        int hm = std::stoi(halfMoveClock);
        int fm = std::stoi(fullMoveNumber);
        if (hm < 0 || fm < 1) {
            return false;
        }
    } catch (std::exception e) {
        return false;
    }

    // If all checks passed, FEN is valid
    return true;
}
