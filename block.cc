#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "block.h"
#include "gameBoard.h"

using namespace std;

Block::Block(gameBoard * pBoard) {
	board = pBoard;
    current_level = pBoard->getLevel();
}

Block::~Block(){}

void Block::setLevel(int level){
	current_level = level;
}

vector<Cell *> Block::getCells() {
	return cells;
}

char Block::getBlockType() {
	return block_type;
}

bool Block::isLegalMove(int pX, int pY) {
	for(int i = 0; i < 4; ++i) {
		int tmpX = cells.at(i)->x+pX;
		int tmpY = cells.at(i)->y+pY;
		if(!isLegalXY(tmpX,tmpY)) {
			cout << "it is not legal" << endl;
			return false;
		}
	}
	cout << "it is legal" << endl;
	return true;
}

void Block::left() {
	if(this->isLegalMove(0,-1)) {
		for (int i = 0; i < 4; ++i) {
			move_ID(i,cells.at(i)->x,cells.at(i)->y-1);
		}
	}
}

void Block::right() {
	if(this->isLegalMove(0,1)) {
		for (int i = 0; i < 4; ++i) {
			move_ID(i,cells.at(i)->x,cells.at(i)->y+1);
		}
	}
}

void Block::down() {
	if(this->isLegalMove(1,0)) {
		for (int i = 0; i < 4; ++i) {
			move_ID(i,cells.at(i)->x+1,cells.at(i)->y);
		}
	}
}

void Block::move_ID(int i,int x_new, int y_new){
	
	int ID_temp = cells.at(i)->block_id;
	cells.at(i)->block_id = -1;
	cells.at(i)->setXY(x_new,y_new);
	cells.at(i)->block_id = ID_temp;
}

bool Block::isLegalXY(int x, int y) {
	if(x < 0 || x > (NUM_ROWS-1) || y < 0 || y > (NUM_COLS-1) || board->getCell(x,y)->filled){ 
		return false;
	}
	return true;
}

void Block::drawNextBlock(std::string nblock, int j) {

		
	int width = 25;
	int height = 25;
	for(int i = 0; i < nblock.size();i++){

	if(nblock[i] == ' '){
		w->fillRectangle(300 + i*25,300 + j*25,width,height,Xwindow::White);
	}else if(nblock[i] == 'I'){
		w->fillRectangle(300 + i*25,300 + j*25,width,height,Xwindow::Red);
	}else if(nblock[i] == 'J'){
		w->fillRectangle(300 + i*25,300 + j*25,width,height,Xwindow::Green);
	}else if(nblock[i] == 'L'){
		w->fillRectangle(300 + i*25,300 + j*25,width,height,Xwindow::Blue);
	}else if(nblock[i] == 'O'){
		w->fillRectangle(300 + i*25,300 + j*25,width,height,Xwindow::Cyan);
	}else if(nblock[i] == 'Z'){
		w->fillRectangle(300 + i*25,300 + j*25,width,height,Xwindow::Yellow);
	}else if(nblock[i] == 'S'){
		w->fillRectangle(300 + i*25,300 + j*25,width,height,Xwindow::Magenta);
	}else if(nblock[i] == 'T'){
		w->fillRectangle(300 + i*25,300 + j*25,width,height,Xwindow::Orange);
	}
	}


}

ostream &operator<<(ostream &out, Block &bl) {
	
	int c = 0;
	int temp = 0;
	if(bl.board->getGraphics()) {
			bl.w = bl.board->getWindow();
			bl.w->fillRectangle(280,280,200,200,Xwindow::White);
	}
	stringstream ss;
	for(int i = 0; i < 4 && c < 4; ++i) {
		for(int j = 0; j < 4 && c < 4; ++j) {
			//if the cell is here, put the cell's content instead of a space
			if(bl.cells.at(c)->x == i && bl.cells.at(c)->y == j) {
				ss << *bl.cells.at(c);
				c++;
			} else {
				ss << ' ';
			}
		}
		//if the stringstream only contains spaces, we don't need it
		if(ss.str().find_first_not_of(' ') != std::string::npos) {
			out << ss.str() << endl;
		}
		if(bl.board->getGraphics()) {
			bl.drawNextBlock(ss.str(),temp);
		}
		temp++;
		//
		ss.str("");
	}
	
	return out;
}
