#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"

class oBlock : public Block {

 public:
  oBlock(gameBoard * pBoard, int pId);
  ~oBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
  virtual void left();
  virtual void right();
  virtual void down();
};
#endif
