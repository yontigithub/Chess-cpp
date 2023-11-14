//
// Created by Yonatan Rappoport on 13/11/2023.
//

#include "king.h"

King::King(pos_t position, color_t color) : Piece(KING, position, color) {

}

bool King::IsLegalMove(const pos_t &reached) const {
    if (!IsValidPos(reached)) {
        throw InvalidPosition(reached);
    }

    // Implementation

    return ((reached != m_position) &&
            abs(reached.first - m_position.first) <= 1 &&
            abs(reached.second - m_position.second) <= 1);
}