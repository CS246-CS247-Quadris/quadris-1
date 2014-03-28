#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

class tBlock : public Block {

  Cell **cells;

 public:
  tBlock();
  ~tBlock();
  virtual void rotateCCW();
  virtual void rotateCW();

 friend std::ostream &operator<<(std::ostream &out, const iBlock &bl);
	
};
#endif
