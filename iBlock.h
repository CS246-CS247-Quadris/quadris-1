#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"

class iBlock : public Block {
 public:
  iBlock(gameBoard * pBoard, int pId);
  ~iBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
};
#endif
