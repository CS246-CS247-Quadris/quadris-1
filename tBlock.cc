#include "tBlock.h"
using namespace std;

tBlock::tBlock(gameBoard * pBoard, int pId):Block(pBoard) {
	cells.push_back(new Cell(pId,1,0,'T',current_level,true));
	cells.push_back(new Cell(pId,1,1,'T',current_level,true));
	cells.push_back(new Cell(pId,1,2,'T',current_level,true));
	cells.push_back(new Cell(pId,2,1,'T',current_level,true));
}

tBlock::~tBlock() {}

void tBlock::rotateCCW() {
    if(cells.at(1)->x < cells.at(3)->x) {
if(isLegalXY(cells.at(0)->x+1,cells.at(0)->y+1) && isLegalXY(cells.at(1)->x,cells.at(1)->y) && isLegalXY(cells.at(2)->x-1,cells.at(2)->y-1) && isLegalXY(cells.at(3)->x-1,cells.at(3)->y+1)){
	/*cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x-1,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x-1,cells.at(3)->y+1);*/
	move_ID(0,cells.at(0)->x+1,cells.at(0)->y+1);
	move_ID(1,cells.at(1)->x,cells.at(1)->y);
	move_ID(2,cells.at(2)->x-1,cells.at(2)->y-1);
	move_ID(3,cells.at(3)->x-1,cells.at(3)->y+1);
	}else{
		//cout << "it is not legal" << endl;
	}
  } else if(cells.at(1)->y < cells.at(3)->y){
if(isLegalXY(cells.at(0)->x,cells.at(0)->y+1) && isLegalXY(cells.at(1)->x+1,cells.at(1)->y) && isLegalXY(cells.at(2)->x+2,cells.at(2)->y-1) && isLegalXY(cells.at(3)->x,cells.at(3)->y-1)){
	/*cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+2,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y-1);*/
	move_ID(0,cells.at(0)->x,cells.at(0)->y+1);
	move_ID(1,cells.at(1)->x+1,cells.at(1)->y);
	move_ID(2,cells.at(2)->x+2,cells.at(2)->y-1);
	move_ID(3,cells.at(3)->x,cells.at(3)->y-1);
	}else{
		//cout << "it is not legal" << endl;
	}
  }else if(cells.at(1)->x > cells.at(3)->x){
if(isLegalXY(cells.at(0)->x-2,cells.at(0)->y-1) && isLegalXY(cells.at(1)->x-1,cells.at(1)->y) && isLegalXY(cells.at(2)->x,cells.at(2)->y+1) && isLegalXY(cells.at(3)->x,cells.at(3)->y-1)){
	/*cells.at(0)->setXY(cells.at(0)->x-2,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y-1);*/
	move_ID(0,cells.at(0)->x-2,cells.at(0)->y-1);
	move_ID(1,cells.at(1)->x-1,cells.at(1)->y);
	move_ID(2,cells.at(2)->x,cells.at(2)->y+1);
	move_ID(3,cells.at(3)->x,cells.at(3)->y-1);
	}else{
		//cout << "it is not legal" << endl;
	}
  }else if(cells.at(1)->y > cells.at(3)->y){
if(isLegalXY(cells.at(0)->x+1,cells.at(0)->y-1) && isLegalXY(cells.at(1)->x,cells.at(1)->y) && isLegalXY(cells.at(2)->x-1,cells.at(2)->y+1) && isLegalXY(cells.at(3)->x+1,cells.at(3)->y+1)){
	/*cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x-1,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y+1);*/

	move_ID(0,cells.at(0)->x+1,cells.at(0)->y-1);
	move_ID(1,cells.at(1)->x,cells.at(1)->y);
	move_ID(2,cells.at(2)->x-1,cells.at(2)->y+1);
	move_ID(3,cells.at(3)->x+1,cells.at(3)->y+1);
	}else{
		//cout << "it is not legal" << endl;
	}
  }
}

void tBlock::rotateCW() {
    if(cells.at(1)->x < cells.at(3)->x) {
if(isLegalXY(cells.at(0)->x-1,cells.at(0)->y+1) && isLegalXY(cells.at(1)->x,cells.at(1)->y) && isLegalXY(cells.at(2)->x+1,cells.at(2)->y-1) && isLegalXY(cells.at(3)->x-1,cells.at(3)->y-1)){
	/*cells.at(0)->setXY(cells.at(0)->x-1,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x-1,cells.at(3)->y-1);*/

	move_ID(0,cells.at(0)->x-1,cells.at(0)->y+1);
	move_ID(1,cells.at(1)->x,cells.at(1)->y);
	move_ID(2,cells.at(2)->x+1,cells.at(2)->y-1);
	move_ID(3,cells.at(3)->x-1,cells.at(3)->y-1);
	}else{
		//cout << "it is not legal" << endl;
	}
  } else if(cells.at(1)->y > cells.at(3)->y){
if(isLegalXY(cells.at(0)->x+2,cells.at(0)->y+1) && isLegalXY(cells.at(1)->x+1,cells.at(1)->y) && isLegalXY(cells.at(2)->x,cells.at(2)->y-1) && isLegalXY(cells.at(3)->x,cells.at(3)->y+1)){
	/*cells.at(0)->setXY(cells.at(0)->x+2,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y+1);*/

	move_ID(0,cells.at(0)->x+2,cells.at(0)->y+1);
	move_ID(1,cells.at(1)->x+1,cells.at(1)->y);
	move_ID(2,cells.at(2)->x,cells.at(2)->y-1);
	move_ID(3,cells.at(3)->x,cells.at(3)->y+1);
	}else{
		cout << "it is not legal" << endl;
	}
  }else if(cells.at(1)->x > cells.at(3)->x){
if(isLegalXY(cells.at(0)->x,cells.at(0)->y-1) && isLegalXY(cells.at(1)->x-1,cells.at(1)->y) && isLegalXY(cells.at(2)->x-2,cells.at(2)->y+1) && isLegalXY(cells.at(3)->x,cells.at(3)->y+1)){
	/*cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x-1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x-2,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y+1);*/

	move_ID(0,cells.at(0)->x,cells.at(0)->y-1);
	move_ID(1,cells.at(1)->x-1,cells.at(1)->y);
	move_ID(2,cells.at(2)->x-2,cells.at(2)->y+1);
	move_ID(3,cells.at(3)->x,cells.at(3)->y+1);
	}else{
		//cout << "it is not legal" << endl;
	}
  }else if(cells.at(1)->y < cells.at(3)->y){
if(isLegalXY(cells.at(0)->x-1,cells.at(0)->y-1) && isLegalXY(cells.at(1)->x,cells.at(1)->y) && isLegalXY(cells.at(2)->x+1,cells.at(2)->y+1) && isLegalXY(cells.at(3)->x+1,cells.at(3)->y-1)){
	/*cells.at(0)->setXY(cells.at(0)->x-1,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y-1);*/

	move_ID(0,cells.at(0)->x-1,cells.at(0)->y-1);
	move_ID(1,cells.at(1)->x,cells.at(1)->y);
	move_ID(2,cells.at(2)->x+1,cells.at(2)->y+1);
	move_ID(3,cells.at(3)->x+1,cells.at(3)->y-1);
	}else{
		//cout << "it is not legal" << endl;
	}
  }
}
