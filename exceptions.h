//
// Created by Yonatan Rappoport on 14/11/2023.
//

#ifndef CHESS_CPP_EXCEPTIONS_H
#define CHESS_CPP_EXCEPTIONS_H

#include "utils.h"

class InvalidPosition : public std::exception {
protected:
    std::string message_m;
public:
    explicit InvalidPosition(const pos_t& pos) : message_m( "Invalid Position. Given " + posToString(pos) + " out of bounds.") {}
    const char* what() const noexcept override {
        return message_m.c_str();
    }
};

class NotYourPiece : public std::exception {
protected:
    std::string message_m;
public:
    explicit NotYourPiece(const color_t& color) : message_m("You can only move " + ((color == WHITE) ? std::string("white") : std::string("black")) + " pieces.") {}
    const char* what() const noexcept override {
        return message_m.c_str();
    }
};

class IllegalMove : public std::exception {
protected:
    std::string message;
public:
    explicit IllegalMove(const std::string& msg = "Illegal move attempted.") : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class SelfCapture : public IllegalMove {
public:
    SelfCapture() : IllegalMove("Can't move to squares occupied by your own pieces.") {}
};

class EmptySquare : public IllegalMove {
public:
    explicit EmptySquare(const pos_t& pos) : IllegalMove("No piece to move. Given " + posToString(pos) + " empty square.") {}
};

class IllegalPieceMove : public IllegalMove {
public:
    explicit IllegalPieceMove(const std::string& piece) : IllegalMove("Illegal " + piece + " move. ") {}
};

class BlockedPath : public IllegalMove {
public:
    explicit BlockedPath() : IllegalMove("Path blocked.") {}
};


#endif //CHESS_CPP_EXCEPTIONS_H
