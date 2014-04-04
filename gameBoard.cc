#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
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
	isGraphics = true;
	srand(time(NULL));
	fileName = "sequence.txt";
	
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

	if(isGraphics){
		xw = new Xwindow();
		initGameBoardGraphics();
		textGraphics();
	}
}

gameBoard::~gameBoard(){
	for(int i = 0; i < NUM_ROWS; ++i) {
		for(int j = 0; j < NUM_COLS; ++j) {
			delete board[i][j];
		}
	}
	delete board;
	
	delete currentBlock;
	delete nextBlock;
	delete xw;
}

void gameBoard::restart() {
	xw->fillRectangle(280,0,200,100,Xwindow::White);
	for(int i = 0; i < NUM_ROWS; ++i) {
		for(int j = 0; j < NUM_COLS; ++j) {
			delete board[i][j];
			board[i][j] = new Cell(i,j);
		}
	}
	delete nextBlock;

	currentScore = 0;
	levelZeroCount = 1;

	currentBlock = generateBlock();
	nextBlock = generateBlock();

	this->postMove();
	if(isGraphics){
		initGameBoardGraphics();
		textGraphics();
	}
	gameOver = false;
}

Block * gameBoard::generateBlock() {
	blockCounter++;
	switch(level) {
		case 0: {
			char blockType;
			ifstream file(fileName.c_str());
			for(int i = 0; i < levelZeroCount; ++i) {
				file >> blockType;
				
				//if we reached the end of file, go back to beginning and grab that block
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
	isGraphics = false;
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
	bool no_neighbour = true;
	//span a 4 cell area in each direction to see if there are same IDs
	for(int i = -3; i <=3 ; ++i){
		for(int j = -3; j <=3; ++j){
			if(x+i < NUM_ROWS and x+i > 3 and y+j < NUM_COLS and y+j >= 0 and (i !=0 or j != 0) and x+i != x){
				if(getCell(x+i,y+j)->block_id == id and id >=0){
					no_neighbour = false;
				}
			}
		}
	}
	return no_neighbour;
}

void gameBoard::calculateScore() {
	int numLinesCleared = 0;
	//start looking for full rows from the bottom
	for(int i = NUM_ROWS-1; i > 3; --i) {
		bool fullLine = true;
		for(int j = 0; j < NUM_COLS && fullLine; ++j) {
			if(getCell(i+numLinesCleared,j)->block_type == ' ') {
				fullLine = false;
			}
		}
		if(fullLine) {
			//go through each cell in the line and see if any neighbouring cells have the same unique ID
			for(int j = 0; j < NUM_COLS; ++j) {
				if(checkNeighbourId(i+numLinesCleared,j)) {
					bool id_used = false;
					for (vector<int>::iterator it = used_ids.begin() ; it != used_ids.end(); ++it) {
						if((*it) == getCell(i+numLinesCleared,j)->block_id){
							id_used = true;
						}
					}
					//add the bonus if no matching IDs were found
					if(!id_used){
						cout << "COMPLETE BLOCK DELETED ID" << getCell(i+numLinesCleared,j)->block_id <<"  Levelcreated: "<<getCell(i+numLinesCleared,j)->levelCreated <<endl;
						used_ids.push_back(getCell(i+numLinesCleared,j)->block_id);
						int block_bonus = getCell(i+numLinesCleared,j)->levelCreated + 1;
						currentScore += block_bonus * block_bonus;
					}
				}
			}
			//remove the line right away
			//that means that i must be relative
			remove(i+numLinesCleared);
			numLinesCleared++;
		}
	}
	//only add score if you actually cleared lines
	if(numLinesCleared != 0) { 
		int added_score = (level+numLinesCleared)*(level+numLinesCleared);
		currentScore += added_score; 
	}
	if(currentScore > hiScore) hiScore = currentScore;
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
//	initGameBoardGraphics();
}

bool gameBoard::isGameOver() {
	//check if any blocks on the 3rd row, passed the playing area
	for(int j = 0; j < NUM_COLS; ++j) {
		if(getCell(3,j)->filled) return true;
	}
	return false;
}

Cell * gameBoard::getCell(int x, int y) {
	return board[x][y];
}

void gameBoard::levelUp() {
	level == 3 ? level = 3 : level++;
	textGraphics();
}

void gameBoard::levelDown() {
	level == 0 ? level = 0 : level--;
	textGraphics();
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
	currentBlock->left();
	this->postMove();
	if(isGraphics){
		initGameBoardGraphics();
	}
}

void gameBoard::right() {
	this->preMove();
	currentBlock->right();
	this->postMove();
	if(isGraphics){
		initGameBoardGraphics();
	}
}

void gameBoard::down() {
	this->preMove();
	currentBlock->down();
	this->postMove();
	if(isGraphics){
		initGameBoardGraphics();
	}
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
	delete currentBlock;

	if(this->isGameOver()) {
		//restart the game
		gameOver = true;
		cout << "GAME OVER" << endl;
		if(isGraphics) xw->drawBigString(280,50,"GAME OVER",Xwindow::Black);
		//this->restart();
	} else {
		//point to a new block
		currentBlock = nextBlock;
		this->postMove();
		nextBlock = generateBlock();
	}
	if(isGraphics) {
		textGraphics();
		initGameBoardGraphics();	
	}
}

void gameBoard::rotateCW() {
	this->preMove();
	currentBlock->rotateCW();
	this->postMove();
	if(isGraphics){
		initGameBoardGraphics();
	}
}

void gameBoard::rotateCCW() {
	this->preMove();
	currentBlock->rotateCCW();
	this->postMove();
	if(isGraphics){
		initGameBoardGraphics();
	}
}
void gameBoard::initGameBoardGraphics(){
	for(int i = 0; i < NUM_ROWS; ++i) {
		for(int j = 0; j < NUM_COLS; j++) {
			board[i][j]->setCoords(j*25,i*25,25,25,xw);
			board[i][j]->draw();
		}
	}
}

Xwindow* gameBoard::getWindow(){
	return xw;
}

void gameBoard::textGraphics(){

	xw->fillRectangle(300,75,200,200,Xwindow::White);
	stringstream ssLevel;
	stringstream ssCurrentScore;
	stringstream ssHiScore;
	ssLevel << "Level:    " << level;
	ssCurrentScore << "Score:    " << currentScore;
	ssHiScore << "Hi Score:    " << hiScore;

	xw->drawString(300, 100, ssLevel.str());
	xw->drawString(300, 150, ssCurrentScore.str());
	xw->drawString(300, 200, ssHiScore.str());
	xw->drawString(300, 250, "Next: ");
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
