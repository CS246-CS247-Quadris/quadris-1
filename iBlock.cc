#include "iBlock.h"
#include "gameBoard.h"
#define SIZE 4
using namespace std;

iBlock::iBlock(gameBoard * pBoard):Block(pBoard) {
	cells.push_back(new Cell(3,0,'i',current_level,true));
	cells.push_back(new Cell(3,1,'i',current_level,true));
	cells.push_back(new Cell(3,2,'i',current_level,true));
	cells.push_back(new Cell(3,3,'i',current_level,true));
	block_type = 'i';
	current_block_id++;
}
iBlock::~iBlock() {}

void iBlock::rotateCCW() {
	rotateCW();
}

void iBlock::rotateCW() {
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

void iBlock::left(){
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y-1);
}
void iBlock::right(){
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y+1);

}
void iBlock::down(){
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y);
}

bool iBlock::isLegalRotate(int pDirection) {
	int tmpX, tmpY;
	switch(pDirection) {
		case 0:
			for(int i = 1; i < 4; ++i) {
				tmpX = cells.at(i)->x;
				tmpY = cells.at(i)->y-i;
				if(tmpX < 0 || tmpX > (NUM_ROWS-1) || tmpY < 0 || tmpY > (NUM_COLS-1)) return false;
				if(board->getCell(tmpX,tmpY)->filled) return false;
			}
			break;
		case 1:
			for(int i = 1; i < 4; ++i) {
				tmpX = cells.at(i)->x-i;
				tmpY = cells.at(i)->y;
				if(tmpX < 0 || tmpX > (NUM_ROWS-1) || tmpY < 0 || tmpY > (NUM_COLS-1)) return false;
				if(board->getCell(tmpX,tmpY)->filled) return false;
			}
			break;
	}
	return true;
}