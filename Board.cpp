//
// Created by mfbut on 4/24/2019.
//

#include <iostream>
#include "Board.h"

TicTacToeGame::Board::Board(int boardSize, char blankChar) :
    boardState(boardSize, std::string(boardSize, blankChar)),
    blankChar(blankChar) {

}

int TicTacToeGame::Board::getSize() const {
  return boardState.size();
}

void TicTacToeGame::Board::display() const {

  //print column headers
  std::cout << "  ";
  for (int i = 0; i < getSize(); ++i) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  int rowIndex = 0;
  for (const auto& row : boardState) {
    std::cout << rowIndex << ' ';
    for(const auto& elem : row){
      std::cout << elem << ' ';
    }
    rowIndex++;
    std::cout << std::endl;
  }
}

bool TicTacToeGame::Board::inBounds(int row, int col) const {
  return isBetween(row, 0, getSize()-1) &&
  isBetween(col, 0, getSize() - 1);
}

bool TicTacToeGame::Board::isBetween(int val, int lower, int upper) {
  return val >= lower && val <= upper;
}

bool TicTacToeGame::Board::isBlankSpace(int row, int col) const {
  return boardState.at(row).at(col) == blankChar;
}

void TicTacToeGame::Board::set(int row, int col, char val) {
  boardState.at(row).at(col) = val;
}

TicTacToeGame::Board::iterator TicTacToeGame::Board::begin() {
  return boardState.begin();
}

TicTacToeGame::Board::iterator TicTacToeGame::Board::end() {
  return boardState.end();
}

TicTacToeGame::Board::const_iterator TicTacToeGame::Board::cbegin() const {
  return boardState.cbegin();
}

TicTacToeGame::Board::const_iterator TicTacToeGame::Board::cend() const {
  return  boardState.cend();
}

const char TicTacToeGame::Board::getBlankChar() const {
  return blankChar;
}

const char& TicTacToeGame::Board::at(int row, int col) const {
  return boardState.at(row).at(col);
}

bool TicTacToeGame::Board::full() const {
  for (int row = 0; row < getSize(); ++row) {
    for (int col = 0; col < getSize(); ++col) {
      if(!isBlankSpace(row, col)){
        return false;
      }
    }
  }
  return true;
}
