#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"

class sBlock : public Block {

 public:
  sBlock(gameBoard * pBoard, int pId);
  ~sBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
};
#endif
