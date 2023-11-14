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

    if (m_color == WHITE) {
        if (reached.second == m_position.second) {
            if (m_position.first == PAWN_ROW && reached.first - m_position.first == 2) {
                return true; // Double pawn move at starting row
            }

            if (reached.first - m_position.first == 1) {
                return true;// Regular move
            }
        } else {
            // todo: should this case be included?
        }
    }
    else {
        if (reached.second == m_position.second) {
            if (m_position.first == BOARD_SIZE - PAWN_ROW - 1 && reached.first - m_position.first == -2) {
                return true; // Double pawn move at starting row
            }

            if (reached.first - m_position.first == -1) {
                return true;// Regular move
            }
        } else {
            // todo: should this case be included?
        }
    }

    return false;
}