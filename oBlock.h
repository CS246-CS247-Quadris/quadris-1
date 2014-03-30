#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"

class oBlock : public Block {

 public:
  oBlock(gameBoard * pBoard);
  ~oBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
  virtual void left();
  virtual void right();
  virtual void down();
  //virtual bool isLegalRotate(int pDirection); //0 - clockwise, 1 - counterclockwise	
};
#endif
