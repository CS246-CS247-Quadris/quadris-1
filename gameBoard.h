#include <iostream>
#include <string>

class Cell;
class Block;

class gameBoard {
	Cell ***board;
	Block * availableBlocks[7];
	Block * currentBlock;
	Block * nextBlock;
	int currentPosition[2];
	int level;
	int currentScore;
	int hiScore;
	//Xwindow * xw;
	bool isGraphics;
	double seed;
	std::istream * file;

	Block * generateBlock();
	public:
		gameBoard();
		~gameBoard();
		void setSeed(int pSeed);
		void setLevel(int pLevel);
		void setLevelZeroFile(std::istream * pFile);
		//Block getCurrentBlock();
		//Block getNextBlock();
		void setGraphics();
		bool getGraphics();
		void calculateScore();
		void remove(int row);
		//bool isLegal(int pPosition[2]);
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
