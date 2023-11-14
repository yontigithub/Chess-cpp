//
// Created by Yonatan Rappoport on 13/11/2023.
//

#ifndef CHESS_CPP_UTILS_H
#define CHESS_CPP_UTILS_H

#include <iostream>

typedef enum {BISHOP, KING, KNIGHT, PAWN, QUEEN, ROOK} piece_t;
typedef std::pair<char, char> pos_t;
typedef enum {WHITE, BLACK} color_t;

const int board_size = 8;

bool IsValidPos(const pos_t& pos) {
    return (pos.first >= 0 && pos.second >= 0 && pos.first < 8 && pos.second < 8);
}

#endif //CHESS_CPP_UTILS_H
