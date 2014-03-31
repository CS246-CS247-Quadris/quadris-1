#include "sBlock.h"
using namespace std;
sBlock::sBlock(gameBoard * pBoard):Block(pBoard) {
	cells.push_back(new Cell(1,1,'S',current_level,true));
	cells.push_back(new Cell(1,2,'S',current_level,true));
	cells.push_back(new Cell(2,0,'S',current_level,true));
	cells.push_back(new Cell(2,1,'S',current_level,true));
	current_block_id++;
}
sBlock::~sBlock() {}

void sBlock::rotateCCW() {

  rotateCW();
}

void sBlock::rotateCW() {
    if(cells.at(2)->x == cells.at(3)->x) {
if(isLegalXY(cells.at(0)->x,cells.at(0)->y) && isLegalXY(cells.at(1)->x+1,cells.at(1)->y-1) && isLegalXY(cells.at(2)->x-2,cells.at(2)->y) && isLegalXY(cells.at(3)->x-1,cells.at(3)->y-1)){
	cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x-2,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x-1,cells.at(3)->y-1);
	}else{
		cout << "it is not legal" << endl;
	}
  } else{
if(isLegalXY(cells.at(0)->x,cells.at(0)->y) && isLegalXY(cells.at(1)->x-1,cells.at(1)->y+1) && isLegalXY(cells.at(2)->x+2,cells.at(2)->y) && isLegalXY(cells.at(3)->x+1,cells.at(3)->y+1)){
	cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x+2,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y+1);
	}else{
		cout << "it is not legal" << endl;
	}
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
