#include <iostream>
#include <string>
#include <cstdlib>
#include "cell.h"
#include "block.h"
#include "gameBoard.h"
#include "iBlock.h"
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

	//define available blocks [put s and z blocks at the back of array]
	//availableBlocks[] = {};

	//define blocks
	currentBlock = generateBlock();
	nextBlock = generateBlock();
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

Block * gameBoard::generateBlock() {
	switch(level) {
		case 0:
			//read the next one from file...do we need a counter in the meantime
			break;
		case 1: {
			int i = rand() % 12;
			switch(i) {
				case 0:
					return(availableBlocks[5]);
					break;
				case 1:
					return(availableBlocks[6]);
					break;
				default:
					int j = rand() % 5;
					return(availableBlocks[j]);
					break;
			}
			break;
		}
		case 2: {
			int i = rand() % 7;
			return(availableBlocks[i]);
			break;
		}
		case 3: {
			int i = rand() % 9;
			switch(i) {
				case 0: case 1:
					return(availableBlocks[5]);
					break;
				case 2: case 3:
					return(availableBlocks[6]);
					break;
				default:
					int j = rand() % 5;
					return(availableBlocks[j]);
					break;
			}
			break;
		}
	}
	return NULL;
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

void gameBoard::setLevelZeroFile(std::istream * pFile) {
	file = pFile;
}

void gameBoard::calculateScore() {

}

void gameBoard::remove(int row) {

}

// bool gameBoard::isLegal(int pPostion[]) {	
// 	return true;		
// }

void gameBoard::levelUp() {
	level == 3 ? level = 3 : level++;
}

void gameBoard::levelDown() {
	level == 0 ? level = 0 : level--;
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
