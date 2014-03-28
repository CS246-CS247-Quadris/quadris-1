#include <iostream>
#include <string>
#include "block.h"
#define SIZE 4
using namespace std;

Block::Block() {
	cells = new Cell * [SIZE];
	for(int i = 0; i < SIZE; ++i) {
		cells[i] = new Cell[SIZE];
		for(int j = 0; j < SIZE; ++j) {
			cells[i][j].x = i;
			cells[i][j].y = j;
		}
	}
        current_level = 0;
        current_block_id = 0;
}
Block::~Block(){}

ostream &operator<<(ostream &out, const Block &bl) {
	for(int i = 0; i < SIZE; ++i) {
		string tmp;
		for(int j = 0; j < SIZE; ++j) {
			tmp += bl.cells[i][j].block_type;
		}
		//i'm looking for a row that has a part of the block, not 100% sure this works though
		if(tmp.find_first_not_of(' ') != string::npos) {
			out << tmp << endl;
		}
	}
	return out;
}
