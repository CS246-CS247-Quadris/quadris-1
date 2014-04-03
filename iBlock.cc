#include "iBlock.h"

using namespace std;

iBlock::iBlock(gameBoard * pBoard, int pId):Block(pBoard) {
	cells.push_back(new Cell(pId,3,0,'I',current_level,true));
	cells.push_back(new Cell(pId,3,1,'I',current_level,true));
	cells.push_back(new Cell(pId,3,2,'I',current_level,true));
	cells.push_back(new Cell(pId,3,3,'I',current_level,true));
	block_type = 'I';
}
iBlock::~iBlock() {}

void iBlock::rotateCCW() {
	rotateCW();
}

void iBlock::rotateCW() {
  if(cells.at(0)->x != cells.at(3)->x) {
	if(isLegalXY(cells.at(0)->x,cells.at(0)->y) && isLegalXY(cells.at(1)->x+1,cells.at(1)->y+1) && isLegalXY(cells.at(2)->x+2,cells.at(2)->y+2) && isLegalXY(cells.at(3)->x+3,cells.at(3)->y+3)){
		cout << "it is legal" << endl;
		cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y);
		cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y+1);
		cells.at(2)->setXY(cells.at(2)->x+2,cells.at(2)->y+2);
		cells.at(3)->setXY(cells.at(3)->x+3,cells.at(3)->y+3);
	} else {
		cout << "it is not legal" << endl;
	}
  } else {
	if(isLegalXY(cells.at(0)->x,cells.at(0)->y) && isLegalXY(cells.at(1)->x-1,cells.at(1)->y-1) && isLegalXY(cells.at(2)->x-2,cells.at(2)->y-2) && isLegalXY(cells.at(3)->x-3,cells.at(3)->y-3)) {
		cout << "it is legal" << endl;
		cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y);
		cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y-1);
		cells.at(2)->setXY(cells.at(2)->x-2,cells.at(2)->y-2);
		cells.at(3)->setXY(cells.at(3)->x-3,cells.at(3)->y-3);
	} else {
		cout << "it is not legal" << endl;
	}
  }
}