//
// Created by mfbut on 4/26/2019.
//

#ifndef TICTACTOE_MOVE_H
#define TICTACTOE_MOVE_H
#include <sstream>
#include "Player.h"
#include "Board.h"
namespace TicTacToeGame {

class Move {
 public:
  Move(const Player& maker);
  void parseInput(std::stringstream& input);
  bool isValid(const Board& board) const;
  void make(Board& board);
 private:
  const Player& maker;
  int row, col;
  bool parsedSuccessfully;

};
}

#endif //TICTACTOE_MOVE_H
