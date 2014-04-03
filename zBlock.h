#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"

class zBlock : public Block {

 public:
  zBlock(gameBoard * pBoard, int pId);
  ~zBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
};
#endif
