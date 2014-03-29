#include "iBlock.h"
#include <iostream>
#include <string>
#define SIZE 4
using namespace std;

iBlock::iBlock():Block() {
	cells[0][0].filled = true;
	cells[0][0].block_type = 'i';
	cells[1][0].filled = true;
	cells[2][0].filled = true;
	cells[3][0].filled = true;
	current_block_id++;
}
iBlock::~iBlock() {}

void iBlock::rotateCCW() {
	rotateCW();
}

void iBlock::rotateCW() {
  if(cells[0][0].filled) {
	cells[0][0].filled = false;
	cells[1][0].filled = false;
	cells[2][0].filled = false;
	cells[3][1].filled = true;
	cells[3][2].filled = true;
	cells[3][3].filled = true;
  } else {
	cells[0][0].filled = true;
	cells[1][0].filled = true;
	cells[2][0].filled = true;
	cells[3][1].filled = false;
	cells[3][2].filled = false;
	cells[3][3].filled = false;
  }
}