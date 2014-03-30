#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"

class sBlock : public Block {

 public:
  sBlock(gameBoard * pBoard);
  ~sBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
  virtual void left();
  virtual void right();
  virtual void down();
  virtual bool isLegalRotate(int pDirection); //0 - clockwise, 1 - counterclockwise
	
};
#endif
