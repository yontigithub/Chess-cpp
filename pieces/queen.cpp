//
// Created by Yonatan Rappoport on 13/11/2023.
//

#include "queen.h"

Queen::Queen(pos_t position, color_t color) : Piece(QUEEN, position, color) {

}

bool Queen::IsLegalMove(const pos_t &reached) const {
    if (!IsValidPos(reached)) {
        throw InvalidPosition(reached);
    }

    // Implementation
}