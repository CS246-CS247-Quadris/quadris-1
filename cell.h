#ifndef __CELL_H__
#define __CELL_H__


class Cell {

 public:
  Cell();
  ~Cell();
  int block_id;
  char block_type;
  int levelCreated;
  bool filled;

};
#endif
