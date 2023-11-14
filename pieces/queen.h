//
// Created by Yonatan Rappoport on 13/11/2023.
//

#ifndef CHESS_CPP_QUEEN_H
#define CHESS_CPP_QUEEN_H

#include "piece.h"

class Queen : Piece {
public:
    Queen(pos_t position, color_t color);
    bool IsLegalMove(const pos_t& reached) const override;

private:

};

#endif //CHESS_CPP_QUEEN_H
