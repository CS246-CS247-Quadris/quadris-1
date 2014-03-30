#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"

class lBlock : public Block {

 public:
  lBlock(gameBoard * pBoard);
  ~lBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
  virtual void left();
  virtual void right();
  virtual void down();
	
};
#endif
