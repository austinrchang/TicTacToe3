cmake_minimum_required(VERSION 3.13)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToe main.cpp TicTacToe.cpp TicTacToe.h Board.cpp Board.h Player.cpp Player.h Move.cpp Move.h)
add_compile_options(TicTacToe PRIVATE -Wall -Werror)
