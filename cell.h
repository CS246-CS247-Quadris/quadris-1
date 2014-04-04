#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "window.h"
class Cell {

//for graphical output
int i, j, width, height;
Xwindow * w;
 public:
  Cell();
  Cell(int x, int y);
  Cell(int id, int x, int y, char block_type, int levelCreated, bool filled);
  ~Cell();
  void setXY(int pX, int pY);
  int x;
  int y;
  int block_id;
  char block_type;
  int levelCreated;
  bool filled;
  void setCoords( int x, int y, int width, int height, Xwindow *w);
  friend std::ostream &operator<<(std::ostream &out, const Cell &c);
  void setCoords(int i, int j, int width, int height);
   void draw();
  void undraw();
};
#endif
