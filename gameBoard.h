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
	int currentScore;
	int hiScore;
	//Xwindow * xw;
	bool isGraphics;
	double seed;
	std::istream * file;

	Block * generateBlock();
	void preMove();
	void postMove();
	public:
		gameBoard();
		~gameBoard();
		void setSeed(int pSeed);
		void setLevel(int pLevel);
		void setLevelZeroFile(std::istream * pFile);
		Cell * getCell(int x, int y);
		//Block getCurrentBlock();
		//Block getNextBlock();
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
