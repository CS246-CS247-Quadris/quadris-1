#include <iostream>
#include <string>
#include "cell.h"
#include "block.h"
#include "gameBoard.h"
#define NUM_ROWS 18
#define NUM_COLS 10

using namespace std;

gameBoard::gameBoard() {

	level = 0;
	currentScore = 0;
	hiScore = 0;
	isGraphics = false;
	seed = 0;
	
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

	//define available blocks
	//availableBlocks[] = {};

	//define blocks
	currentBlock = NULL;
	nextBlock = NULL;
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


	board = new Cell **[NUM_ROWS];
	for(int i = 0; i < NUM_ROWS; ++i) {
		board[i] = new Cell * [NUM_COLS];
		for(int j = 0; j < NUM_COLS; j++) {
			board[i][j] = new Cell(i,j);
		}
	}

	//define blocks, but we need to get new ones ASAP
	currentBlock = NULL;
	nextBlock = NULL;
}

void gameBoard::setSeed(int pSeed) {
	seed = pSeed;
}

void gameBoard::setGraphics() {
	isGraphics = true;
}

bool gameBoard::getGraphics() {
	return isGraphics;
}

void gameBoard::setLevel(int pLevel) {
	level = pLevel;
}
void gameBoard::calculateScore() {

}

void gameBoard::remove() {

}


bool gameBoard::isLegal(int pPostion[]) {
return true;		
}

void gameBoard::levelUp() {
}

void gameBoard::levelDown() {

}

void gameBoard::left() {
}

void gameBoard::right() {
}

void gameBoard::down() {
}

void gameBoard::drop() {
}

void gameBoard::rotateCW() {

}

void gameBoard::rotateCCW() {

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
