#include "jBlock.h"

jBlock::jBlock(gameBoard * pBoard):Block(pBoard) {
	cells.push_back(new Cell(3,0,'j',current_level,true));
	cells.push_back(new Cell(3,1,'j',current_level,true));
	cells.push_back(new Cell(3,2,'j',current_level,true));
	cells.push_back(new Cell(2,0,'j',current_level,true));
	current_block_id++;
}
jBlock::~jBlock() {}

void jBlock::rotateCCW() {
	rotateCW();
}

void jBlock::rotateCW() {
  if(cells.at(0)->x != cells.at(3)->x) {
	cells.at(1)->setXY(cells.at(0)->x,cells.at(0)->y-1);
	cells.at(2)->setXY(cells.at(0)->x,cells.at(0)->y-2);
	cells.at(3)->setXY(cells.at(0)->x,cells.at(0)->y-3);
  } else {
	cells.at(1)->setXY(cells.at(0)->x-1,cells.at(0)->y);
	cells.at(2)->setXY(cells.at(0)->x-2,cells.at(0)->y);
	cells.at(3)->setXY(cells.at(0)->x-3,cells.at(0)->y);
  }
}

void jBlock::left(){

	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y-1);
	cells.at(2)->setXY(cells.at(3)->x,cells.at(3)->y-1);


}
void jBlock::right(){

	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y+1);
	cells.at(2)->setXY(cells.at(3)->x,cells.at(3)->y+1);

}
void jBlock::down(){
	cells.at(0)->setXY(cells.at(0)->x-1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x-1,cells.at(2)->y);
	cells.at(2)->setXY(cells.at(3)->x-1,cells.at(3)->y);

}
