#include "cell.h"

Cell::Cell() {}
Cell::Cell(int pX, int pY) : x(pX), y(pY) {
	block_id = -1;
	block_type = ' ';
	levelCreated = -1;
	filled = false;
}
Cell::~Cell(){}

std::ostream &operator<<(std::ostream &out, const Cell &c) {
	out << c.block_type;
	return out;
}
