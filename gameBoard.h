#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#include <iostream>
#include <string>
#define NUM_ROWS 18
#define NUM_COLS 10

class Cell;
class Block;

class gameBoard {

	Cell ***board;
	Block * currentBlock;
	Block * nextBlock;
	int level;
	int levelZeroCount;
	int blockCounter;
	int currentScore;
	int hiScore;
	//Xwindow * xw;
	bool isGraphics;
	std::string fileName;

	Block * generateBlock();
	void preMove();
	void postMove();
	bool checkNeighbourId(int x, int y);
	public:
		gameBoard();
		~gameBoard();
		void setSeed(int pSeed);
		void setLevel(int pLevel);
		int getLevel();
		void setFileName(std::string pFileName);
		Cell * getCell(int x, int y);
		void setGraphics();
		bool getGraphics();
		void calculateScore();
		void remove(int row);
		bool isLegal();
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