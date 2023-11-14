//
// Created by Yonatan Rappoport on 13/11/2023.
//

#ifndef CHESS_CPP_KING_H
#define CHESS_CPP_KING_H

#include <iostream>
#include "piece.h"

class King : Piece {
public:
    King(pos_t position, color_t color);

private:
    bool IsLegalMove(const pos_t& reached) const override;
};

#endif //CHESS_CPP_KING_H
