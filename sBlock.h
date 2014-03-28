#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"

class sBlock : public Block {

  Cell **cells;

 public:
  sBlock();
  ~sBlock();
  virtual void rotateCCW();
  virtual void rotateCW();

 friend std::ostream &operator<<(std::ostream &out, const iBlock &bl);
	
};
#endif
