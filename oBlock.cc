#include "oBlock.h"

oBlock::oBlock(gameBoard * pBoard, int pId):Block(pBoard) {
	cells.push_back(new Cell(pId,1,0,'O',current_level,true));
	cells.push_back(new Cell(pId,1,1,'O',current_level,true));
	cells.push_back(new Cell(pId,2,0,'O',current_level,true));
	cells.push_back(new Cell(pId,2,1,'O',current_level,true));
}
oBlock::~oBlock() {}

void oBlock::rotateCCW() {
	std::cout << "it is legal" << std::endl;
}

void oBlock::rotateCW() {
	std::cout << "it is legal" << std::endl;
}