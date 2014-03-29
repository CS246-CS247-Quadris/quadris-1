#include "iBlock.h"
#include <iostream>
#include <string>
#define SIZE 4
using namespace std;

iBlock::iBlock():Block() {
	cells.push_back(Cell(0,0,'i',current_level,true));
	cells.push_back(Cell(1,0,'i',current_level,true));
	cells.push_back(Cell(2,0,'i',current_level,true));
	cells.push_back(Cell(3,0,'i',current_level,true));
	current_block_id++;
}
iBlock::~iBlock() {}

void iBlock::rotateCCW() {
	rotateCW();
}

void iBlock::rotateCW() {
  if(cells.at(0).x != cells.at(3).x) {
	cells.at(0).setXY(cells.at(3).x,cells.at(3).y+3);
	cells.at(1).setXY(cells.at(3).x,cells.at(3).y+2);
	cells.at(2).setXY(cells.at(3).x,cells.at(3).y+1);
  } else {
	cells.at(0).setXY(cells.at(3).x-3,cells.at(3).y-3);
	cells.at(1).setXY(cells.at(3).x-2,cells.at(3).y-2);
	cells.at(2).setXY(cells.at(3).x-1,cells.at(3).y-1);

  }
}
