//
// Created by Yonatan Rappoport on 13/11/2023.
//

#include "piece.h"

Piece::Piece(const piece_t &type, const pos_t &pos, const color_t &color) : m_type(type), m_position(pos), m_color(color) {
    if(!IsValidPos(pos)) {
        throw InvalidPosition(pos);
    }
}
