#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cell.h"

class Block {

  Cell **cells;

 public:
  Block();
  ~Block();
  void left();
  void right();
  void down();
  virtual void rotateCCW()= 0;
  virtual void rotateCW()= 0;
  friend std::ostream &operator<<(std::ostream &out, const Block &bl);	

};
#endif
