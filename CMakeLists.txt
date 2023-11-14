cmake_minimum_required(VERSION 3.23)
project(Chess_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess_cpp
    main.cpp
    pieces/piece.h
    pieces/piece.cpp
    pieces/knight.h
    pieces/knight.cpp
    pieces/bishop.h
    pieces/bishop.cpp
    pieces/king.h
    pieces/king.cpp
    pieces/queen.h
    pieces/queen.cpp
    pieces/rook.h
    pieces/rook.cpp
    pieces/pawn.h
    pieces/pawn.cpp
    utils.h
    exceptions.h)
