#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"

class iBlock : public Block {

  Cell **cells;

 public:
  iBlock();
  ~iBlock();
  virtual void rotateCCW();
  virtual void rotateCW();

 friend std::ostream &operator<<(std::ostream &out, const iBlock &bl);
	
};
#endif
