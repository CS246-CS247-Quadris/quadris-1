#ifndef __IBLOCK_O__
#define __IBLOCK_O__
#include "block.h"

class oBlock : public Block {

  Cell **cells;

 public:
  oBlock();
  ~oBlock();
  virtual void rotateCCW();
  virtual void rotateCW();

 friend std::ostream &operator<<(std::ostream &out, const iBlock &bl);
	
};
#endif
