#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cell.h"
#include <vector>

class gameBoard;

class Block {
 public:
  Block(gameBoard * pBoard);
  ~Block();
  void setLevel(int);
  std::vector<Cell *> getCells();
  char getBlockType();
  virtual void rotateCCW()= 0;
  virtual void rotateCW()= 0;
  void left();
  void right();
  void down();
  friend std::ostream &operator<<(std::ostream &out, const Block &bl);
  bool isLegalMove(int pX, int pY);	//check for left,right,down moves based on distance traveling
  bool isLegalXY(int x, int y);		//check if a cell is filled or off the board
 protected:
  gameBoard * board;
  std::vector<Cell *> cells;
  void move_ID(int,int, int);		//transfer ID, x, and y from cell to cell
  char block_type;
  int current_level;
};

#endif
