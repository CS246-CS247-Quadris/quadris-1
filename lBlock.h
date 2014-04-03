#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"

class lBlock : public Block {

 public:
  lBlock(gameBoard * pBoard, int pId);
  ~lBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
};
#endif
