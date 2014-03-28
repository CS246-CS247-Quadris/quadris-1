#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"

class lBlock : public Block {

  Cell **cells;

 public:
  lBlock();
  ~lBlock();
  virtual void rotateCCW();
  virtual void rotateCW();

 friend std::ostream &operator<<(std::ostream &out, const iBlock &bl);
	
};
#endif
