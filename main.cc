#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "gameBoard.h"
#include "iBlock.h"

using namespace std;

int main(int argc, char * argv[]) {

    string s;
	gameBoard * board = new gameBoard();

	//do the args stuff
	for(int i = 0; i < argc; i++) {
		if(strcmp(argv[i],"-text") == 0) {
			//currently we default text, for now
			//if we get graphics going, change setGraphics to set it to false, and uncomment this
			//board->setGraphics();
		}
		else if(strcmp(argv[i],"-seed") == 0) {
			int s;
			istringstream iss(argv[i+1]);
			iss >> s;
			board->setSeed(s);
			i++;
		}
		else if(strcmp(argv[i],"-scriptfile") == 0) {
			ifstream * file = new ifstream(argv[i+1]);
			board->setLevelZeroFile(file);
			i++;
		}
		else if(strcmp(argv[i],"-startlevel") == 0) {
			int s;
			istringstream iss(argv[i+1]);
			iss >> s;
			board->setLevel(s);
			i++;
		}
	}
	cout << *board;
	//generate the current block and next block on the board
	//blah blah blah

        while(cin >> s) {
		if(s.length() < 2) {
			cerr << "invalid command" << endl;
		} else {
			//get the multiplier if applicable
			int tmp = (int)s[0]-48;
			bool isANum = false;
			int mult = 0;
			while(tmp > -1 && tmp < 10) {
				isANum = true;
				mult = mult*10 + tmp;
				s = s.substr(1,s.length()-1);
				tmp = (int)s[0]-48;
			}
			//default case
			if(!isANum) mult = 1;

			//command autocomplete
			string commands[] = {"clockwise","counterclockwise","down","drop","left","levelup","leveldown","restart","right"};
			string command;
			int cmdPossible = 0;
			for(int i = 0; i < 9; ++i) {
				int found = commands[i].find(s);
				if(found == 0) {
					cmdPossible++;
					command = commands[i];
				}
			}
			if(cmdPossible == 0) { cerr << "no commands found" << endl; }
			else if(cmdPossible > 1) { cerr << "too many possibilities" << endl; }
			else {
				cout << "your command: " << mult << "x " << command << endl;
				if(!command.compare("restart")) { (*board).restart(); }
				else if(!command.compare("levelup")) { for(int i = 0; i < mult; ++i) (*board).levelUp(); }
				else if(!command.compare("leveldown")) { for(int i = 0; i < mult; ++i) (*board).levelDown(); }
				else if(!command.compare("left")) { for(int i = 0; i < mult; ++i) (*board).left(); }
				else if(!command.compare("right")) { for(int i = 0; i < mult; ++i) (*board).right(); }
				else if(!command.compare("down")) { for(int i = 0; i < mult; ++i) (*board).down(); }
				else if(!command.compare("drop")) { for(int i = 0; i < mult; ++i) (*board).drop(); }
				else if(!command.compare("clockwise")) { for(int i = 0; i < mult; ++i) (*board).rotateCW(); }
				else if(!command.compare("counterclockwise")) { for(int i = 0; i < mult; ++i) (*board).rotateCCW(); }
			}
			cout << *board;
			//after the move, probably should check if they lose yet
		}
	}
}
