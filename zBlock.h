#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"

class zBlock : public Block {

 public:
  zBlock(gameBoard * pBoard);
  ~zBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
  virtual void left();
  virtual void right();
  virtual void down();
virtual bool isLegalRotate(int pDirection); //0 - clockwise, 1 - counterclockwise
	
};
#endif
