//
// Created by mfbut on 4/24/2019.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H
#include <vector>
#include <string>
namespace TicTacToeGame {
class Board {
 public:
  using iterator = std::vector<std::string>::iterator;
  using const_iterator = std::vector<std::string>::const_iterator;


  explicit Board(int boardSize, char blankChar);
  int getSize() const;
  void display() const;
  bool inBounds(int row, int col) const;
  bool isBlankSpace(int row, int col) const;
  void set(int row, int col, char val);

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  const char& at(int row, int col) const;

  const char getBlankChar() const;
  bool full() const;

 private:
  static bool isBetween(int val, int lower, int upper);

 private:
  std::vector<std::string> boardState;
  const char blankChar;

};
}

#endif //TICTACTOE_BOARD_H
