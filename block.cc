#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "block.h"

using namespace std;

Block::Block() {
        current_level = 0;
        current_block_id = 0;
}
Block::~Block(){}

void Block::setLevel(int level){
	current_level = level;
}

void Block::left(){

	cells.at(0).setXY(cells.at(0).x,cells.at(0).y-1);
	cells.at(1).setXY(cells.at(1).x,cells.at(1).y-1);
	cells.at(2).setXY(cells.at(2).x,cells.at(2).y-1);
	cells.at(2).setXY(cells.at(3).x,cells.at(3).y-1);


}
void Block::right(){

	cells.at(0).setXY(cells.at(0).x,cells.at(0).y+1);
	cells.at(1).setXY(cells.at(1).x,cells.at(1).y+1);
	cells.at(2).setXY(cells.at(2).x,cells.at(2).y+1);
	cells.at(2).setXY(cells.at(3).x,cells.at(3).y+1);

}
void Block::down(){
	cells.at(0).setXY(cells.at(0).x-1,cells.at(0).y);
	cells.at(1).setXY(cells.at(1).x-1,cells.at(1).y);
	cells.at(2).setXY(cells.at(2).x-1,cells.at(2).y);
	cells.at(2).setXY(cells.at(3).x-1,cells.at(3).y);

}

ostream &operator<<(ostream &out, const Block &bl) {
	int c = 0;
	stringstream ss;
	for(int i = 0; i < 4 && c < 4; ++i) {
		for(int j = 0; j < 4 && c < 4; ++j) {
			if(bl.cells.at(c).x == i && bl.cells.at(c).y == j) {
				ss << bl.cells.at(c);
				c++;
			} else {
				ss << ' ';
			}
		}
		if(ss.str().find_first_not_of(' ') != std::string::npos) {
			out << ss.str() << endl;
		}
		ss.str("");
	}
	return out;
}
