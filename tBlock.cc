#include "tBlock.h"

tBlock::tBlock(gameBoard * pBoard):Block(pBoard) {
	cells.push_back(new Cell(2,0,'T',current_level,true));
	cells.push_back(new Cell(2,1,'T',current_level,true));
	cells.push_back(new Cell(2,2,'T',current_level,true));
	cells.push_back(new Cell(3,1,'T',current_level,true));
	current_block_id++;
}

tBlock::~tBlock() {}

void tBlock::rotateCCW() {
    if(cells.at(1)->x < cells.at(3)->x) {
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x-1,cells.at(2)->y-2);
	cells.at(3)->setXY(cells.at(3)->x-1,cells.at(3)->y);
  } else if(cells.at(1)->y < cells.at(3)->y){
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y+2);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x+2,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y);
  }else if(cells.at(1)->x > cells.at(3)->x){
	cells.at(0)->setXY(cells.at(0)->x-2,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y-1);
  }else if(cells.at(1)->y > cells.at(3)->y){
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x-1,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y+1);
  }
}

void tBlock::rotateCW() {
    if(cells.at(1)->x < cells.at(3)->x) {
	cells.at(0)->setXY(cells.at(0)->x-1,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x-1,cells.at(3)->y-1);
  } else if(cells.at(1)->y > cells.at(3)->y){
	cells.at(0)->setXY(cells.at(0)->x+2,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y+1);
  }else if(cells.at(1)->x > cells.at(3)->x){
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y-2);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x-2,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y);
  }else if(cells.at(1)->y < cells.at(3)->y){
	cells.at(0)->setXY(cells.at(0)->x-1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y+2);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y);
  }
}

void tBlock::left(){
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y-1);
}

void tBlock::right(){
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y+1);
}

void tBlock::down(){
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y);
}