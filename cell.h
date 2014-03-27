#ifndef __CELL_H__
#define __CELL_H__


class Cell {

 public:
  Cell();
  Cell(int x, int y);
  ~Cell();
  int x;
  int y;
  int block_id;
  char block_type;
  int levelCreated;
  bool filled;
  friend std::ostream &operator<<(std::ostream &out, const Cell &c);
};
#endif
