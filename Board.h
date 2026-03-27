//
// Created by Yonatan Rappoport on 24/03/2026.
//

#ifndef CHESS_CPP_BOARD_H
#define CHESS_CPP_BOARD_H


#include "exceptions.h"
#include "util.h"
#include <cmath>


class Board {
public:
    Board() : turn_m(WHITE), white_king({4,0}), black_king({4,7}) {
        board_m[0][0] = new Piece(ROOK, WHITE);
        board_m[1][0] = new Piece(KNIGHT, WHITE);
        board_m[2][0] = new Piece(BISHOP, WHITE);
        board_m[3][0] = new Piece(QUEEN, WHITE);
        board_m[4][0] = new Piece(KING, WHITE);
        board_m[5][0] = new Piece(BISHOP, WHITE);
        board_m[6][0] = new Piece(KNIGHT, WHITE);
        board_m[7][0] = new Piece(ROOK, WHITE);

        board_m[0][7] = new Piece(ROOK, BLACK);
        board_m[1][7] = new Piece(KNIGHT, BLACK);
        board_m[2][7] = new Piece(BISHOP, BLACK);
        board_m[3][7] = new Piece(QUEEN, BLACK);
        board_m[4][7] = new Piece(KING, BLACK);
        board_m[5][7] = new Piece(BISHOP, BLACK);
        board_m[6][7] = new Piece(KNIGHT, BLACK);
        board_m[7][7] = new Piece(ROOK, BLACK);

        for (int i = 0; i < 8; ++i) {
            board_m[i][1] = new Piece(PAWN, WHITE);
            board_m[i][6] = new Piece(PAWN, BLACK);
        }
    }


    void can_move(const pos_t& src, const pos_t&dst) { // throws exception if can't
        if (!IsValidPos(src)) throw InvalidPosition(src);
        if (!IsValidPos(dst)) throw InvalidPosition(dst);

        if (board_m[src.first][src.second] == nullptr) throw EmptySquare(src);
        if (board_m[src.first][src.second]->color_m != turn_m) throw NotYourPiece(turn_m);

        bool capture = board_m[dst.first][dst.second] != nullptr;

        if (capture)
            if (board_m[dst.first][dst.second]->color_m == turn_m)
                throw SelfCapture();

        piece_t type = board_m[src.first][src.second]->type_m;


        if (type == BISHOP) {
            if(abs(src.first - dst.first) != abs(src.second - dst.second)) throw IllegalPieceMove("bishop");
            if(!checkEmpty(src,dst,board_m)) throw BlockedPath();
            if (capture) delete board_m[dst.first][dst.second];
        } else if (type == KING) {
            if (abs(dst.second - src.second) > 1 || abs(dst.first - src.first) > 1) throw IllegalPieceMove("king");
            if (capture) delete board_m[dst.first][dst.second];
            if (turn_m == WHITE) white_king = dst;
            else black_king = dst;

        } else if (type == KNIGHT) {
            if ((abs(dst.second - src.second) != 1 || abs(dst.first - src.first) != 2) &&
                (abs(dst.first - src.first) != 1 || abs(dst.second - src.second) != 2)) {
                throw IllegalPieceMove("knight");
            }
            if (capture) delete board_m[dst.first][dst.second];
        } else if (type == PAWN) {
            int direction = 2*(int)(turn_m == WHITE) - 1; // for pawn movement direction
            int starting_row = (turn_m == WHITE) ? 1 : 6; // for first 2-step move rule

            if (capture) {
                if(dst.second != src.second + direction || abs(dst.first - src.first) != 1) throw IllegalPieceMove("pawn");
                delete board_m[dst.first][dst.second];
                // todo: en-passant
            } else {
                if (dst.first != src.first) throw IllegalPieceMove("pawn");
                if (src.second == starting_row && dst.second == src.second + 2*direction) {
                    // two steps
                    if (board_m[src.first][src.second+direction]) throw BlockedPath();
                } else if (dst.second != src.second + direction) throw IllegalPieceMove("pawn");
            }
        } else if (type == QUEEN) {
            if (src.first != dst.first && src.second != dst.second && abs(src.first - dst.first) != abs(src.second - dst.second))
                throw IllegalPieceMove("queen");
            if (!checkEmpty(src,dst,board_m)) throw BlockedPath();
            if (capture) delete board_m[dst.first][dst.second];
        } else if (type == ROOK) {
            if (src.first != dst.first && src.second != dst.second) throw IllegalPieceMove("rook");
            if (!checkEmpty(src,dst,board_m)) throw BlockedPath();
            if (capture) delete board_m[dst.first][dst.second];
        }
    }
    void move(const pos_t& src, const pos_t& dst) {
        can_move(src, dst);
        board_m[dst.first][dst.second] = board_m[src.first][src.second];
        board_m[src.first][src.second] = nullptr;
        turn_m = (turn_m == WHITE ? BLACK : WHITE);

    }

    std::pair<pos_t, pos_t> getMove() {
        std::cout << (turn_m == WHITE ? "White" : "Black") << "'s turn: ";
        std::pair<pos_t, pos_t> a;
        std::cin >> a.first.first >> a.first.second >> a.second.first >> a.second.second;
        return a;
    }

    bool isAttacked(const color_t& player, const pos_t& pos) {
        // player - player that I am getting attacked

        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                if (!board_m[x][y]) continue;
                if (board_m[x][y]->color_m == player) continue;
                try {
                    can_move({x,y}, pos);
                    return true;
                } catch(...) {
                    continue;
                }
            }
        }

        return false;
    }

    bool isCheckMate(const color_t& player) {
        pos_t king = (player == WHITE) ? white_king : black_king;
        // remember to check for king captures
    }

private:
    Piece* board_m[8][8] = {};
    color_t turn_m;
    pos_t white_king, black_king;


    friend std::ostream& operator<<(std::ostream& os, const Board& b) {
        for (int y = 7; y >= 0; --y) {
            for (int x = 0; x < 8; ++x) {
                if ((x+y)%2) os << "\033[48;5;208m"; // orange bg
                else os << "\x1b[44m"; // blue bg
                if(b.board_m[x][y])
                    os << " " << *b.board_m[x][y];
                else os << "  \x1b[m"; // reset attrs

                if ((x+y)%2) os << "\033[48;5;208m"; // orange bg
                else os << "\x1b[44m"; // blue bg
                os << " \x1b[m";// reset formatting
            }
            os << '\n';
        }
        return os;
    }
};


#endif //CHESS_CPP_BOARD_H
