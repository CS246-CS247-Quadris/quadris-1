#include <iostream>
#include <string>
#include <sstream>
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

void Block::setLevel(int level){
	current_level = level;
}

ostream &operator<<(ostream &out, const Block &bl) {
	stringstream ss;
	for(int i = 0; i < SIZE; ++i) {
		for(int j = 0; j < SIZE; ++j) {
			ss << bl.cells[i][j].block_type;
		}
		
		string tmp = ss.str();
		if(!tmp.empty()) {
			out << tmp << endl;
		}
		ss.str("");
	}
	return out;
}
