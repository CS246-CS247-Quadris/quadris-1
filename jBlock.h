#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"

class jBlock : public Block {

  Cell **cells;

 public:
  iBlock();
  ~iBlock();
  virtual void rotateCCW();
  virtual void rotateCW();

 friend std::ostream &operator<<(std::ostream &out, const iBlock &bl);
	
};
#endif
