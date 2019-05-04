//
// Created by mfbut on 4/24/2019.
//
#include <iostream>
#include <sstream>
#include "Move.h"
#include "TicTacToe.h"

TicTacToeGame::TicTacToe::TicTacToe(int boardSize) :
    board(boardSize, '*'), players(2), playerTurn(-1) {

}

void TicTacToeGame::TicTacToe::play() {
  determineStartingPlayer();

  while (true) {
    board.display(); //show the game state
    //get move
    Move move = getValidMove();
    //make move
    move.make(board);
    //makeMove(move);
    if (isGameOver()) {
      break;
    }
    //switch the turn
    changeTurn();
  }
  //
  board.display();
  //declare the results
  declareResults();

}

void TicTacToeGame::TicTacToe::determineStartingPlayer() {
  playerTurn = 0;
}

TicTacToeGame::Move TicTacToeGame::TicTacToe::getValidMove() const {
  Move playerMove(getCurrentPlayer());
  do {
    std::cout << "Enter the row column pair you want to play in: ";
    std::string line;
    std::getline(std::cin, line);
    std::stringstream userIn(line);
    playerMove.parseInput(userIn);
  } while (!playerMove.isValid(board));
  return playerMove;
}

const TicTacToeGame::Player& TicTacToeGame::TicTacToe::getCurrentPlayer() const {
  return players.at(playerTurn);
}

TicTacToeGame::Player& TicTacToeGame::TicTacToe::getCurrentPlayer() {
  return players.at(playerTurn);
}

bool TicTacToeGame::TicTacToe::isGameOver() const {
  return gameWon() || tie();
}

bool TicTacToeGame::TicTacToe::gameWon() const {
  return horzWin() || vertWin() || diagWin();
}

bool TicTacToeGame::TicTacToe::horzWin() const {
  for (auto rowItr = board.cbegin(); rowItr != board.cend(); ++rowItr) {
    auto elemItr = rowItr->cbegin();
    if (*elemItr == board.getBlankChar()) {
      continue;
    }
    const char firstElem = *elemItr;
    bool allSame = true;
    for (; elemItr != rowItr->cend(); ++elemItr) {
      if (*elemItr != firstElem) {
        allSame = false;
        break;
      }
    }
    if (allSame) {
      return true;
    }
  }
  return false;
}

bool TicTacToeGame::TicTacToe::vertWin() const {
  for (int col = 0; col != board.getSize(); ++col) {
    if (board.isBlankSpace(0, col)) {
      continue;
    }
    bool allSame = true;
    const char firstChar = board.at(0, col);
    for (int row = 0; row != board.getSize(); ++row) {
      if (board.at(row, col) != firstChar) {
        allSame = false;
        break;
      }
    }
    if (allSame) {
      return true;
    }
  }
  return false;
}

//X
//  X
//    X

bool TicTacToeGame::TicTacToe::diagWin() const {
  return leftDiagWin() || rightDiagWin();
}

//X
//  X
//    X
bool TicTacToeGame::TicTacToe::leftDiagWin() const {
  if (board.isBlankSpace(0, 0)) {
    return false;
  } else {
    const char firstChar = board.at(0, 0);
    for (int i = 0; i < board.getSize(); ++i) {
      if (board.at(i, i) != firstChar) {
        return false;
      }
    }
    return true;
  }
}

//    X
//  X
//X
bool TicTacToeGame::TicTacToe::rightDiagWin() const {
  if (board.isBlankSpace(0, board.getSize() - 1)) {
    return false;
  } else {
    const char firstChar = board.at(0, board.getSize() - 1);
    for (int i = 0; i < board.getSize(); ++i) {
      if (board.at(i, board.getSize() - 1 - i) != firstChar) {
        return false;
      }
    }
    return true;
  }
}

bool TicTacToeGame::TicTacToe::tie() const {
  return !gameWon() && board.full();
}

void TicTacToeGame::TicTacToe::changeTurn() {
  playerTurn = (playerTurn + 1) % players.size();
}

void TicTacToeGame::TicTacToe::declareResults() const {
  if (tie()) {
    std::cout << "Tie Game" << std::endl;
  } else {
    std::cout << getCurrentPlayer().getName() << " won the game!" << std::endl;
  }
}


