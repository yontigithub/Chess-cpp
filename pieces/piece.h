//
// Created by Yonatan Rappoport on 13/11/2023.
//

#ifndef CHESS_CPP_PIECE_H
#define CHESS_CPP_PIECE_H

#include <iostream>
#include "../utils.h"
#include "../exceptions.h"

class Piece {
public:

    Piece(const piece_t &type, const pos_t &pos, const color_t &color);


private:
    piece_t m_type;

protected:
    pos_t m_position;
    color_t m_color;
    virtual bool IsLegalMove(const pos_t& reached) const = 0;


};

#endif //CHESS_CPP_PIECE_H
