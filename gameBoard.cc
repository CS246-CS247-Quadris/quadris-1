#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>
#include "cell.h"
#include "block.h"
#include "gameBoard.h"
#include "iBlock.h"
#include "jBlock.h"
#include "oBlock.h"
#include "sBlock.h"
#include "zBlock.h"
#include "lBlock.h"
#include "tBlock.h"

using namespace std;

gameBoard::gameBoard() {

	level = 0;
	blockCounter = 0;
	levelZeroCount = 1;
	currentScore = 0;
	hiScore = 0;
	isGraphics = false;
	srand(time(NULL));
	fileName = "sequence.txt";
	
	//xw = new XWindow();
	//xw = NULL;

	//initialize the board
	board = new Cell **[NUM_ROWS];
	for(int i = 0; i < NUM_ROWS; ++i) {
		board[i] = new Cell * [NUM_COLS];
		for(int j = 0; j < NUM_COLS; j++) {
			board[i][j] = new Cell(i,j);
		}
	}

	//define blocks
	currentBlock = generateBlock();
	nextBlock = generateBlock();

	//Put the current block in the grid
	this->postMove();
}

gameBoard::~gameBoard(){
	for(int i = 0; i < NUM_ROWS; ++i) {
		for(int j = 0; j < NUM_COLS; ++j) {
			delete board[i][j];
		}
		delete board[i];
	}
	delete board;
	
	delete currentBlock;
	delete nextBlock;
	//delete xw;
}

void gameBoard::restart() {
	for(int i = 0; i < NUM_ROWS; ++i) {
		for(int j = 0; j < NUM_COLS; ++j) {
			delete board[i][j];
		}
		delete board[i];
	}
	delete board;
	
	delete currentBlock;
	delete nextBlock;

	currentScore = 0;
	levelZeroCount = 1;

	board = new Cell **[NUM_ROWS];
	for(int i = 0; i < NUM_ROWS; ++i) {
		board[i] = new Cell * [NUM_COLS];
		for(int j = 0; j < NUM_COLS; j++) {
			board[i][j] = new Cell(i,j);
		}
	}

	currentBlock = generateBlock();
	nextBlock = generateBlock();

	this->postMove();
}

Block * gameBoard::generateBlock() {
	blockCounter++;
	switch(level) {
		case 0: {
			char blockType;
			ifstream file(fileName.c_str());
			for(int i = 0; i < levelZeroCount; ++i) {
				file >> blockType;
				if(file.eof()) {
					file.clear();
					file.seekg(0, file.beg);
					file >> blockType;
					levelZeroCount = 1;
				}
			}
			levelZeroCount++;
			switch(blockType) {
				case 'I': { return new iBlock(this,blockCounter); break; }
				case 'J': { return new jBlock(this,blockCounter); break; }
				case 'O': { return new oBlock(this,blockCounter); break; }
				case 'S': { return new sBlock(this,blockCounter); break; }
				case 'Z': { return new zBlock(this,blockCounter); break; }
				case 'L': { return new lBlock(this,blockCounter); break; }
				case 'T': { return new tBlock(this,blockCounter); break; }
			}
			break;
		}
		case 1: {
			int i = rand() % 12;
			switch(i) {
				case 0:
					return new sBlock(this,blockCounter);
					break;
				case 1:
					return new zBlock(this,blockCounter);
					break;
				default:
					int j = rand() % 5;
					if(j == 0) { return new iBlock(this,blockCounter); }
					if(j == 1) { return new jBlock(this,blockCounter); }
					if(j == 2) { return new lBlock(this,blockCounter); }
					if(j == 3) { return new oBlock(this,blockCounter); }
					if(j == 4) { return new tBlock(this,blockCounter); }
				break;
			}
			break;
		}
		case 2: {
			int i = rand() % 7;
			if(i == 0) { return new iBlock(this,blockCounter); }
			if(i == 1) { return new jBlock(this,blockCounter); }
			if(i == 2) { return new lBlock(this,blockCounter); }
			if(i == 3) { return new oBlock(this,blockCounter); }
			if(i == 4) { return new sBlock(this,blockCounter); }
			if(i == 5) { return new zBlock(this,blockCounter); }
			if(i == 6) { return new tBlock(this,blockCounter); }
			break;
		}
		case 3: {
			int i = rand() % 9;
			switch(i) {
				case 0: case 1:
					return new sBlock(this,blockCounter);
					break;
				case 2: case 3:
					return new zBlock(this,blockCounter);
					break;
				default:
					int j = rand() % 5;
					if(j == 0) { return new iBlock(this,blockCounter); }
					if(j == 1) { return new jBlock(this,blockCounter); }
					if(j == 2) { return new lBlock(this,blockCounter); }
					if(j == 3) { return new oBlock(this,blockCounter); }
					if(j == 4) { return new tBlock(this,blockCounter); }
					break;
			}
			break;
		}
	}
	return NULL;
}

void gameBoard::setSeed(int pSeed) {
	srand(pSeed);
}

void gameBoard::setGraphics() {
	isGraphics = true;
}

bool gameBoard::getGraphics() {
	return isGraphics;
}

void gameBoard::setFileName(string pFileName) {
	fileName = pFileName;
}

void gameBoard::setLevel(int pLevel) {
	level = pLevel;
}

int gameBoard::getLevel() {
	return level;
}

bool gameBoard::checkNeighbourId(int x, int y) {
	int id = getCell(x,y)->block_id;
	if(x+1 < NUM_ROWS-3) {
		if(getCell(x+1,y)->block_id == id) return false;
	}
	if(x-1 >= 0) {
		if(getCell(x-1,y)->block_id == id) return false;
	}
	if(y+1 < NUM_COLS) {
		if(getCell(x,y+1)->block_id == id) return false;
	}
	if(y-1 >= 0) {
		if(getCell(x,y-1)->block_id == id) return false;
	}
	return true;
}

void gameBoard::calculateScore() {
	int numLinesCleared = 0;
	for(int i = NUM_ROWS-1; i > 3; --i) {
		bool fullLine = true;
		for(int j = 0; j < NUM_COLS && fullLine; ++j) {
			if(getCell(i+numLinesCleared,j)->block_type == ' ') {
				fullLine = false;
			}
		}
		if(fullLine) {
			//go through each cell in the line and see if any neighbouring cells have the same unique ID
			//if so, no points for block clear
			//but it doesn't work right now
			for(int j = 0; j < NUM_COLS; ++j) {
				if(checkNeighbourId(i-numLinesCleared,j)) {
					cout << "cOMPLETE BLOCK DELETED " << getCell(i+numLinesCleared,j)->levelCreated <<endl;
					int block_bonus = getCell(i+numLinesCleared,j)->levelCreated + 1;
					currentScore += block_bonus * block_bonus;
				}
			}
			remove(i+numLinesCleared);
			numLinesCleared++;
		}
	}
	if(numLinesCleared != 0) { 
		int added_score = (level+numLinesCleared)*(level+numLinesCleared);
		//cout << "INSIDESSCORE " << currentScore <<" ADDING"<<sdfs<<endl;
		currentScore += added_score; 
	}
	if(currentScore > hiScore) hiScore = currentScore;	//cout << "cscooore " << currentScore << "num Lines cleared " << numLinesCleared << "whats the leveeel"<< level<<endl;
}

void gameBoard::remove(int row) {
	//delete the row of choice
	//move all the rows down
	//add a new row at the top
	
	for(int i = row; i > 0; --i) {
		for(int j = 0; j < NUM_COLS; ++j) {
			if(i == row) {
				delete board[i][j];
			}
			board[i][j] = board[i-1][j];
		}	
	}
	for(int j = 0; j < NUM_COLS; ++j) {
		board[3][j] = new Cell(3,j);
	}
}

bool gameBoard::isGameOver() {
	//check if any blocks on the 3rd row, passed the playing area
	for(int j = 0; j < NUM_COLS; ++j) {
		if(getCell(2,j)->filled) return true;
	}
	return false;
}
Cell * gameBoard::getCell(int x, int y) {
	return board[x][y];
}

void gameBoard::levelUp() {
	level == 3 ? level = 3 : level++;
}

void gameBoard::levelDown() {
	level == 0 ? level = 0 : level--;
}

void gameBoard::preMove() {
	vector<Cell *> cells = currentBlock->getCells();
	for (vector<Cell *>::iterator it = cells.begin() ; it != cells.end(); ++it) {
		board[(*it)->x][(*it)->y] = new Cell((*it)->x,(*it)->y);
	}
}

void gameBoard::postMove() {
	vector<Cell *> cells = currentBlock->getCells();
	for (vector<Cell *>::iterator it = cells.begin() ; it != cells.end(); ++it) {
		cout << "X/Y: " << (*it)->x << " " << (*it)->y << endl;
		board[(*it)->x][(*it)->y] = *it;
	}
}

void gameBoard::left() {
	this->preMove();
	if(currentBlock->isLegalMove(0,-1)) {
		currentBlock->left();
	}
	this->postMove();
}

void gameBoard::right() {
	this->preMove();
	if(currentBlock->isLegalMove(0,1)) {
		currentBlock->right();
	}
	this->postMove();
}

void gameBoard::down() {
	this->preMove();
	if(currentBlock->isLegalMove(1,0)) {
		currentBlock->down();
	}
	this->postMove();
}

void gameBoard::drop() {
	this->preMove();
	int c = -1;
	bool legal;
	do {
		c++;
		legal = currentBlock->isLegalMove(c,0);
	} while(legal);
	for(int i = 0; i < (c-1); ++i) {
		currentBlock->down();
	}
	this->postMove();
	calculateScore();

	if(this->isGameOver()) {
		cout << "GAME OVER" << endl;
		this->restart();
	} else {
		//point to a new block
		delete currentBlock;
		currentBlock = nextBlock;
		this->postMove();
		nextBlock = generateBlock();
	}
}

void gameBoard::rotateCW() {
	this->preMove();
	currentBlock->rotateCW();
	this->postMove();
}

void gameBoard::rotateCCW() {
	this->preMove();
	currentBlock->rotateCCW();
	this->postMove();
}

ostream &operator<<(ostream &out, const gameBoard &b) {
	//display header
	out << "Level:    " << b.level << endl;
	out << "Score:    " << b.currentScore << endl;
	out << "Hi Score: " << b.hiScore << endl;
	out << "----------" << endl;

	//display game
	for(int i = 0; i < NUM_ROWS; ++i) {
		for(int j = 0; j < NUM_COLS; ++j) {
			out << *(b.board[i][j]);
		}
		out << endl;
	}
	out << "----------" << endl;
	
	//display next block
	out << "Next:" << endl;
	out << *(b.nextBlock);	
	return out;
}
