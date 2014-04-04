#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__
#include <vector>
#include <iostream>
#include <string>
#include "window.h"
#define NUM_ROWS 18
#define NUM_COLS 10

class Cell;
class Block;

class gameBoard {

	Cell ***board;
	Block * currentBlock;
	Block * nextBlock;
	int level;
	int levelZeroCount; 	//counter for level zero loop
	int blockCounter;	//counter for block IDs
	int currentScore;
	int hiScore;
	Xwindow * xw;
	bool isGraphics;
	std::string fileName;
	std::vector<int> used_ids;
	Block * generateBlock();
	void preMove();		//remove the current block from the board
	void postMove();	//put the 'new' current block back onto the board
	bool checkNeighbourId(int x, int y);
	void calculateScore();
	void remove(int row);
	bool isGameOver();
	bool isLegal();
	void initGameBoardGraphics();
	void textGraphics();
	public:
	
		gameBoard();
		~gameBoard();
		void setSeed(int pSeed);
		void setLevel(int pLevel);
		int getLevel();
		void setFileName(std::string pFileName);
		Cell * getCell(int x, int y);
		Xwindow * getWindow();
		void setGraphics();
		bool getGraphics();
		void restart();
		void levelUp();
		void levelDown();
		void left();
		void right();
		void down();
		void drop();
		void rotateCW();
		void rotateCCW();
		friend std::ostream &operator<<(std::ostream &out, const gameBoard &b);
};
#endif
