//
// Created by Yonatan Rappoport on 13/11/2023.
//

#include "knight.h"

Knight::Knight(pos_t position, color_t color) : Piece(KNIGHT, position, color) {

}

bool Knight::IsLegalMove(const pos_t &reached) const {
    if (!IsValidPos(reached)) {
        throw InvalidPosition(reached);
    }

    // Implementation
}