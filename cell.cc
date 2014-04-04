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
	//we really only care about blocktype
	out << c.block_type;
	return out;
}

void Cell::setCoords(int i, int j, int width, int height, Xwindow *w) {

	this->i = i;
	this->j = j;
	this->width = width;
	this->height = height;
	this->w = w;
}

void Cell::setCoords(int i, int j, int width, int height) {

	this->i = i;
	this->j = j;
	this->width = width;
	this->height = height;
}


void Cell::draw() {
	//std::cout<<"i:  "<< i << "j:  "<< j <<std::endl;
	if(block_type == ' '){
		w->fillRectangle(i,j,width,height,Xwindow::Black);
	}else if(block_type == 'I'){
		w->fillRectangle(i,j,width,height,Xwindow::Red);
	}else if(block_type == 'J'){
		w->fillRectangle(i,j,width,height,Xwindow::Green);
	}else if(block_type == 'O'){
		w->fillRectangle(i,j,width,height,Xwindow::Blue);
	}else{
		w->fillRectangle(i,j,width,height,Xwindow::White);
	}

}

void Cell::undraw() {
	w->fillRectangle(i,j,width,height,Xwindow::White);
}
