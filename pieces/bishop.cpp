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

    return ((reached != m_position)  && abs(reached.first - m_position.first) == abs(reached.second - m_position.second));
}