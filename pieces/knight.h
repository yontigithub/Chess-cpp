//
// Created by Yonatan Rappoport on 13/11/2023.
//

#ifndef CHESS_CPP_KNIGHT_H
#define CHESS_CPP_KNIGHT_H

#include <iostream>
#include "piece.h"

class Knight : Piece {
public:
    Knight(pos_t position, color_t color);

private:
    bool IsLegalMove(const pos_t& reached) const override;
};

#endif //CHESS_CPP_KNIGHT_H
