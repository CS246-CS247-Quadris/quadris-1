#include "oBlock.h"

oBlock::oBlock(gameBoard * pBoard):Block(pBoard) {
	cells.push_back(new Cell(0,0,'O',current_level,true));
	cells.push_back(new Cell(0,1,'O',current_level,true));
	cells.push_back(new Cell(1,0,'O',current_level,true));
	cells.push_back(new Cell(1,1,'O',current_level,true));
	current_block_id++;
}
oBlock::~oBlock() {}

void oBlock::rotateCCW() {
	std::cout << "it is legal" << std::endl;
}

void oBlock::rotateCW() {
	std::cout << "it is legal" << std::endl;
}

void oBlock::left(){
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y-1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y-1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y-1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y-1);
}

void oBlock::right(){
	cells.at(0)->setXY(cells.at(0)->x,cells.at(0)->y+1);
	cells.at(1)->setXY(cells.at(1)->x,cells.at(1)->y+1);
	cells.at(2)->setXY(cells.at(2)->x,cells.at(2)->y+1);
	cells.at(3)->setXY(cells.at(3)->x,cells.at(3)->y+1);
}

void oBlock::down(){
	cells.at(0)->setXY(cells.at(0)->x+1,cells.at(0)->y);
	cells.at(1)->setXY(cells.at(1)->x+1,cells.at(1)->y);
	cells.at(2)->setXY(cells.at(2)->x+1,cells.at(2)->y);
	cells.at(3)->setXY(cells.at(3)->x+1,cells.at(3)->y);
}
