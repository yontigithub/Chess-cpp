//
// Created by Yonatan Rappoport on 13/11/2023.
//

#ifndef CHESS_CPP_UTILS_H
#define CHESS_CPP_UTILS_H

#include <iostream>
#include <cmath>

typedef enum {BISHOP, KING, KNIGHT, PAWN, QUEEN, ROOK} piece_t;
typedef std::pair<int, int> pos_t;
typedef enum {WHITE, BLACK} color_t;

const int BOARD_SIZE = 8;
const int PAWN_ROW = 1;

class Piece {
public:
    Piece(piece_t type, color_t color) : type_m(type), color_m(color) {}
    piece_t type_m;
    color_t color_m;

    friend std::ostream& operator<<(std::ostream& os, const Piece& p) {
        if(p.color_m == BLACK) os << "\x1B[30m"; // black fg
        else os << "\x1B[37m"; // white fg


        if (p.type_m == BISHOP) os << 'B';
        else if (p.type_m == KING) os << "\x1B[4m\x1B[3m\x1B[1mK"; // underline, italic, bold
        else if (p.type_m == KNIGHT) os << 'K';
        else if (p.type_m == PAWN) os << 'P';
        else if (p.type_m == QUEEN) os << "\x1B[4m\x1B[3m\x1B[1mQ"; // underline, italic, bold
        else if (p.type_m == ROOK) os << 'R';
        return os << "\x1b[m"; // reset formatting
    }
};

static bool IsValidPos(const pos_t& pos) {
    return (pos.first >= 0 && pos.second >= 0 && pos.first < 8 && pos.second < 8);
}

static std::string posToString(const pos_t& pos) {
    return "(" + std::to_string((int)pos.first) + ", " + std::to_string((int)pos.second) + ")";
}

static bool checkEmpty(const pos_t& src, const pos_t& dst, Piece* board[8][8]) {
    int x_dir = (dst.first > src.first) ? 1 : -1;
    int y_dir = (dst.second > src.second) ? 1 : -1;

    if (src.first == dst.first) {
        for (int y = src.second + y_dir; y != dst.second; y += y_dir)
            if (board[src.first][y] != nullptr)
                return false;

        return true;
    }

    if (src.second == dst.second) {
        for (int x = src.first + x_dir; x != dst.first; x += x_dir)
            if (board[x][src.second] != nullptr)
                return false;

        return true;
    }

    if (abs(src.first - dst.first) == abs(src.second - dst.second)) {

        for (int i = 1; i < abs(src.first - dst.first); ++i)
            if (board[src.first + i * x_dir][src.second + i * y_dir] != nullptr)
                return false;

        return true;
    }

    return false;
}


#endif //CHESS_CPP_UTILS_H
