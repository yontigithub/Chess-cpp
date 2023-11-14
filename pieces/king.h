//
// Created by Yonatan Rappoport on 13/11/2023.
//

#ifndef CHESS_CPP_KING_H
#define CHESS_CPP_KING_H

#include "piece.h"

class King : Piece {
public:
    King(pos_t position, color_t color);
    bool IsLegalMove(const pos_t& reached) const override;

private:
};

#endif //CHESS_CPP_KING_H
