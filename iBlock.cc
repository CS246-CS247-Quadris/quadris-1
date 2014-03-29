#include "iBlock.h"
#include <iostream>
#include <string>
#include "gameBoard.h"
#define SIZE 4
using namespace std;

iBlock::iBlock(gameBoard * pBoard):Block(pBoard) {
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
  if(cells.at(0).filled) {
	cells.at(0).setXY(3,0);
	cells.at(1).setXY(3,1);
	cells.at(2).setXY(3,2);
	cells.at(3).setXY(3,3);
  } else {
  	cells.at(0).setXY(0,0);
	cells.at(1).setXY(1,0);
	cells.at(2).setXY(2,0);
	cells.at(3).setXY(3,0);
  }
}