#include "sBlock.h"

sBlock::sBlock(gameBoard * pBoard):Block(pBoard) {
	cells.push_back(new Cell(3,0,'S',current_level,true));
	cells.push_back(new Cell(3,1,'S',current_level,true));
	cells.push_back(new Cell(2,1,'S',current_level,true));
	cells.push_back(new Cell(2,2,'S',current_level,true));
	current_block_id++;
}
sBlock::~sBlock() {}

void sBlock::rotateCCW() {

  rotateCW();
}

void sBlock::rotateCW() {
    if(cells.at(0)->x == cells.at(1)->x) {
	cells.at(0)->setXY(cells.at(0)->x-2,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y-1);
  } else{
	cells.at(0)->setXY(cells.at(0)->x+2,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x-1,cells.at(3)->y+1);
  }
}

void sBlock::left(){

	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y-1);


}
void sBlock::right(){

	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y+1);

}
void sBlock::down(){
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y);

}

bool sBlock::isLegalRotate(int pDirection) { return true; }
