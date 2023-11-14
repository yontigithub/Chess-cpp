//
// Created by Yonatan Rappoport on 13/11/2023.
//

#ifndef CHESS_CPP_PAWN_H
#define CHESS_CPP_PAWN_H

#include <iostream>
#include "piece.h"

class Pawn : Piece {
public:
    Pawn(pos_t position, color_t color);

private:
    bool IsLegalMove(const pos_t& reached) const override;
};

#endif //CHESS_CPP_PAWN_H
