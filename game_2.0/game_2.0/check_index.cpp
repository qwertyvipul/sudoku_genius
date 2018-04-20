#include<iostream>
#include "tvslib.h"

CheckIndex::CheckIndex(int value, int index, int* puzzle) {
	this->value = value;
	this->index = index;
	this->puzzle = puzzle;
}

int CheckIndex::checkIndex() {
	int rflag, cflag, bflag=0;
	rflag = checkRow();
	if (rflag) cflag = checkCol();
	if (cflag) bflag = checkBox();
	return bflag;
}

int CheckIndex::checkRow() {
	int index = this->index, value = this->value;
	for (int cindex = index - index % 9; cindex<index - index % 9 + 9; cindex++) { //checks all the indexes for the row of the given index
		if (this->puzzle[cindex] == value) return 0; //returns 0 if the value is already present in the row
	}
	return 1;
}

int CheckIndex::checkCol() {
	int index = this->index, value = this->value;
	for (int rindex = index % 9; rindex<81; ) { //checks all the indexes for the row of the given index
		if (this->puzzle[rindex] == value) return 0; //returns 0 if the value is already present in the column
		rindex += 9;
	}
	return 1;
}

int CheckIndex::checkBox() {
	int index = this->index, value = this->value;
	for (int rownum = (index / 27) * 3; rownum<(index / 27) * 3 + 3; rownum++) {
		for (int colnum = (index % 9) - (index % 3); colnum<((index % 9) - (index % 3)) + 3; colnum++) {
			int bindex = rownum * 9 + colnum; //this will give all the indexes for the 3x3 box containing the given index
			if (this->puzzle[bindex] == value) return 0; //returns 0 if the value is already present in the box
		}
		return 1;
	}
