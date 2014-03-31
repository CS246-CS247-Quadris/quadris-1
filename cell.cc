#include "cell.h"

Cell::Cell() {}

Cell::Cell(int pX, int pY) : x(pX), y(pY) {
	block_id = -1;
	block_type = ' ';
	levelCreated = -1;
	filled = false;
}

Cell::Cell(int id, int pX, int pY, char pBlock_Type, int pLevelCreated, bool pFilled) : x(pX), y(pY), block_id(id),
																						block_type(pBlock_Type), levelCreated(pLevelCreated), filled(pFilled) {}

void Cell::setXY(int pX, int pY) {
	x = pX;
	y = pY;
}
Cell::~Cell(){}

std::ostream &operator<<(std::ostream &out, const Cell &c) {
	out << c.block_type;
	return out;
}
