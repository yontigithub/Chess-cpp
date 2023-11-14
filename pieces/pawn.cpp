//
// Created by Yonatan Rappoport on 13/11/2023.
//

#include "pawn.h"

Pawn::Pawn(pos_t position, color_t color) : Piece(PAWN, position, color) {

}

bool Pawn::IsLegalMove(const pos_t &reached) const {
    if (!IsValidPos(reached)) {
        throw InvalidPosition(reached);
    }

    // Implementation
}