#include "lBlock.h"
using namespace std;

lBlock::lBlock(gameBoard * pBoard, int pId):Block(pBoard) {
	cells.push_back(new Cell(pId,1,2,'L',current_level,true));
	cells.push_back(new Cell(pId,2,0,'L',current_level,true));
	cells.push_back(new Cell(pId,2,1,'L',current_level,true));
	cells.push_back(new Cell(pId,2,2,'L',current_level,true));
}

lBlock::~lBlock() {}

void lBlock::rotateCCW() {

    if(cells.at(3)->x > cells.at(0)->x) {
	if(isLegalXY(cells.at(0)->x-1,cells.at(0)->y-2) && isLegalXY(cells.at(1)->x,cells.at(1)->y+1) && isLegalXY(cells.at(2)->x-1,cells.at(2)->y) && isLegalXY(cells.at(3)->x-2,cells.at(3)->y-1)){
	/*cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x-1,cells.at(0)->y-2);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x-1,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x-2,cells.at(3)->y-1);*/

	move_ID(0,cells.at(0)->x-1,cells.at(0)->y-2);
	move_ID(1,cells.at(1)->x,cells.at(1)->y+1);
	move_ID(2,cells.at(2)->x-1,cells.at(2)->y);
	move_ID(3,cells.at(3)->x-2,cells.at(3)->y-1);
	}else{
		//cout << "it is not legal" << endl;
	}
  } else if(cells.at(3)->y > cells.at(0)->y){
if(isLegalXY(cells.at(0)->x+2,cells.at(0)->y) && isLegalXY(cells.at(1)->x-1,cells.at(1)->y+1) && isLegalXY(cells.at(2)->x,cells.at(2)->y) && isLegalXY(cells.at(3)->x+1,cells.at(3)->y-1)){
	/*cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x+2,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y-1);*/

	move_ID(0,cells.at(0)->x+2,cells.at(0)->y);
	move_ID(1,cells.at(1)->x-1,cells.at(1)->y+1);
	move_ID(2,cells.at(2)->x,cells.at(2)->y);
	move_ID(3,cells.at(3)->x+1,cells.at(3)->y-1);
	}else{
		//cout << "it is not legal" << endl;
	}
  }else if(cells.at(3)->x < cells.at(0)->x){
if(isLegalXY(cells.at(0)->x,cells.at(0)->y+1) && isLegalXY(cells.at(1)->x-1,cells.at(1)->y-2) && isLegalXY(cells.at(2)->x,cells.at(2)->y-1) && isLegalXY(cells.at(3)->x+1,cells.at(3)->y)){
	/*cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y-2);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y);*/

	move_ID(0,cells.at(0)->x,cells.at(0)->y+1);
	move_ID(1,cells.at(1)->x-1,cells.at(1)->y-2);
	move_ID(2,cells.at(2)->x,cells.at(2)->y-1);
	move_ID(3,cells.at(3)->x+1,cells.at(3)->y);
	}else{
		//cout << "it is not legal" << endl;
	}
  }else if(cells.at(3)->y < cells.at(0)->y){
	if(isLegalXY(cells.at(0)->x-1,cells.at(0)->y+1) && isLegalXY(cells.at(1)->x+2,cells.at(1)->y) && isLegalXY(cells.at(2)->x+1,cells.at(2)->y+1) && isLegalXY(cells.at(3)->x,cells.at(3)->y+2)){
	/*cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x-1,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x+2,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y+2);*/

	move_ID(0,cells.at(0)->x-1,cells.at(0)->y+1);
	move_ID(1,cells.at(1)->x+2,cells.at(1)->y);
	move_ID(2,cells.at(2)->x+1,cells.at(2)->y+1);
	move_ID(3,cells.at(3)->x,cells.at(3)->y+2);
	}else{
		//cout << "it is not legal" << endl;
	}
  }
}

void lBlock::rotateCW() {
    if(cells.at(3)->x > cells.at(0)->x) {
	if(isLegalXY(cells.at(0)->x+1,cells.at(0)->y-1) && isLegalXY(cells.at(1)->x-2,cells.at(1)->y) && isLegalXY(cells.at(2)->x-1,cells.at(2)->y-1) && isLegalXY(cells.at(3)->x,cells.at(3)->y-2)){
	/*cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x-2,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x-1,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y-2);*/

	move_ID(0,cells.at(0)->x+1,cells.at(0)->y-1);
	move_ID(1,cells.at(1)->x-2,cells.at(1)->y);
	move_ID(2,cells.at(2)->x-1,cells.at(2)->y-1);
	move_ID(3,cells.at(3)->x,cells.at(3)->y-2);
}else{
		//cout << "it is not legal" << endl;
	}
  } else if(cells.at(3)->y < cells.at(0)->y){
if(isLegalXY(cells.at(0)->x,cells.at(0)->y-1) && isLegalXY(cells.at(1)->x+1,cells.at(1)->y+2) && isLegalXY(cells.at(2)->x,cells.at(2)->y+1) && isLegalXY(cells.at(3)->x-1,cells.at(3)->y)){
	/*cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y+2);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x-1,cells.at(3)->y);*/

	move_ID(0,cells.at(0)->x,cells.at(0)->y-1);
	move_ID(1,cells.at(1)->x+1,cells.at(1)->y+2);
	move_ID(2,cells.at(2)->x,cells.at(2)->y+1);
	move_ID(3,cells.at(3)->x-1,cells.at(3)->y);
	}else{
		//cout << "it is not legal" << endl;
	}
  }else if(cells.at(3)->x < cells.at(0)->x){
if(isLegalXY(cells.at(0)->x-2,cells.at(0)->y) && isLegalXY(cells.at(1)->x+1,cells.at(1)->y-1) && isLegalXY(cells.at(2)->x,cells.at(2)->y) && isLegalXY(cells.at(3)->x-1,cells.at(3)->y+1)){
	/*cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x-2,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x-1,cells.at(3)->y+1);*/

	move_ID(0,cells.at(0)->x-2,cells.at(0)->y);
	move_ID(1,cells.at(1)->x+1,cells.at(1)->y-1);
	move_ID(2,cells.at(2)->x,cells.at(2)->y);
	move_ID(3,cells.at(3)->x-1,cells.at(3)->y+1);
}else{
		//cout << "it is not legal" << endl;
	}
  }else if(cells.at(3)->y > cells.at(0)->y){
if(isLegalXY(cells.at(0)->x+1,cells.at(0)->y+2) && isLegalXY(cells.at(1)->x,cells.at(1)->y-1) && isLegalXY(cells.at(2)->x+1,cells.at(2)->y) && isLegalXY(cells.at(3)->x+2,cells.at(3)->y+1)){
	/*cout << "it is legal" << endl;
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y+2);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+2,cells.at(3)->y+1);*/

	move_ID(0,cells.at(0)->x+1,cells.at(0)->y+2);
	move_ID(1,cells.at(1)->x,cells.at(1)->y-1);
	move_ID(2,cells.at(2)->x+1,cells.at(2)->y);
	move_ID(3,cells.at(3)->x+2,cells.at(3)->y+1);
	}else{
		//cout << "it is not legal" << endl;
	}
  }
}
