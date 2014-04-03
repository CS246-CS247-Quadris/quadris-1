#include "zBlock.h"
using namespace std;

zBlock::zBlock(gameBoard * pBoard, int pId):Block(pBoard) {
	cells.push_back(new Cell(pId,1,0,'Z',current_level,true));
	cells.push_back(new Cell(pId,1,1,'Z',current_level,true));
	cells.push_back(new Cell(pId,2,1,'Z',current_level,true));
	cells.push_back(new Cell(pId,2,2,'Z',current_level,true));
}

zBlock::~zBlock() {}

void zBlock::rotateCCW() {

  rotateCW();
}

void zBlock::rotateCW() {
    if(cells.at(2)->x == cells.at(3)->x) {
if(isLegalXY(cells.at(0)->x+1,cells.at(0)->y) && isLegalXY(cells.at(1)->x,cells.at(1)->y-1) && isLegalXY(cells.at(2)->x-1,cells.at(2)->y) && isLegalXY(cells.at(3)->x-2,cells.at(3)->y-1)){
	cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x-1,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x-2,cells.at(3)->y-1);
	}else{
		cout << "it is not legal" << endl;
	}
  } else{
if(isLegalXY(cells.at(0)->x-1,cells.at(0)->y) && isLegalXY(cells.at(1)->x,cells.at(1)->y+1) && isLegalXY(cells.at(2)->x+1,cells.at(2)->y) && isLegalXY(cells.at(3)->x+2,cells.at(3)->y+1)){
	cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x-1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+2,cells.at(3)->y+1);
	}else{
		cout << "it is not legal" << endl;
	}
  }
}