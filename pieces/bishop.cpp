//
// Created by Yonatan Rappoport on 13/11/2023.
//

#include "bishop.h"

Bishop::Bishop(pos_t position, color_t color) : Piece(BISHOP, position, color) {

}

bool Bishop::IsLegalMove(const pos_t &reached) const {
    if (!IsValidPos(reached)) {
        throw InvalidPosition(reached);
    }

    // Implementation
}