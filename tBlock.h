#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

class tBlock : public Block {

 public:
  tBlock(gameBoard * pBoard);
  ~tBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
  virtual void left();
  virtual void right();
  virtual void down();
  virtual bool isLegalRotate(int pDirection);
	
};
#endif
