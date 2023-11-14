//
// Created by Yonatan Rappoport on 13/11/2023.
//

#include "rook.h"

Rook::Rook(pos_t position, color_t color) : Piece(ROOK, position, color) {

}

bool Rook::IsLegalMove(const pos_t &reached) const {
    if (!IsValidPos(reached)) {
        throw InvalidPosition(reached);
    }

    // Implementation

    return ((reached != m_position)  &&
           (reached.first == m_position.first) ||
           (reached.second == m_position.second));
}