#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"

class iBlock : public Block {

 public:
  iBlock(gameBoard * pBoard);
  iBlock &operator= (const iBlock &rhs);
  ~iBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
  virtual void left();
  virtual void right();
  virtual void down();
  virtual bool isLegalRotate(int pDirection); //0 - clockwise, 1 - counterclockwise
};
#endif
