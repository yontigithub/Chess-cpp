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

    return ((reached != m_position)  &&
           ((reached.first == m_position.first) ||
            (reached.second == m_position.second) ||
            abs(reached.first - m_position.first) == abs(reached.second - m_position.second)));
}