#include<iostream>
#include<stdlib.h>

using namespace std;

#include "sudoku.cpp"

void checkIndex(int, int[]);
void checkRow(int, int[]);
void checkCol(int, int[]);
void checkBox(int, int[]);

#include "functions.cpp"

int main(){
	int puzzle[] = {
		0, 7, 5, 0, 9, 0, 0, 0, 6,
		0, 2, 3, 0, 8, 0, 0, 4, 0,
		8, 0, 0, 0, 0, 3, 0, 0, 1,
		5, 0, 0, 7, 0, 2, 0, 0, 0,
		0, 4, 0, 8, 0, 6, 0, 2, 0,
		0, 0, 0, 9, 0, 1, 0, 0, 3,
		9, 0, 0, 4, 0, 0, 0, 0, 7,
		0, 6, 0, 0, 7, 0, 5, 8, 0,
		7, 0, 0, 0, 1, 0, 3, 9, 0
	};
	
	Sudoku sudoku(puzzle);
	sudoku.solve();
	sudoku.print();
}
