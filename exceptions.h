//
// Created by Yonatan Rappoport on 14/11/2023.
//

#ifndef CHESS_CPP_EXCEPTIONS_H
#define CHESS_CPP_EXCEPTIONS_H

#include <iostream>
#include "utils.h"

class InvalidPosition : std::exception {
public:
    InvalidPosition(const pos_t& pos) : m_position(pos) {}
    const char* what() const noexcept override {
        std::string res = "Invalid Position. Given (" + std::to_string((int)m_position.first) + ", " + std::to_string((int)m_position.second) + ") out of bounds.";
        return res.c_str();
    }
private:
    pos_t m_position;
};

#endif //CHESS_CPP_EXCEPTIONS_H
