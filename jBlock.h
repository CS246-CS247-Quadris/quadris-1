#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"

class jBlock : public Block {

 public:
  jBlock(gameBoard * pBoard, int pId);
  ~jBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
};
#endif
