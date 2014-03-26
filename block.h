#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cell.h"

class Block {

  Cell cells[4][4];

 public:
  Block();
  ~Block();
  virtual void rotateCCW()= 0;
  virtual void rotateCW()= 0;
	

};
#endif
