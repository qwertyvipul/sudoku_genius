#include<iostream>
#include<stdlib.h>

using namespace std;


//forward declaration of the functions
int checkIndex(int value, int index, int[81]); //check the probability of a value at the given index
int checkRow(int value, int index, int[]); //check the probability of a value in the row of the index
int checkCol(int value, int index, int[]); //check the probability of a value in the column of the index
int checkBox(int value, int index, int[]); //check the probability of a value in the 3x3 box containing the index


//do not change the order of file inclusion
#include "prob_list.cpp" //include probaility list
#include "empty_list.cpp" //include empty list
#include "sudoku.cpp" //incldue sudoku class
#include "functions.cpp" //include functions definitions

int main(){
	int puzzle[] = { //test puzzle
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
	
	
	Sudoku sudoku(puzzle); //create the sudoku class
	cout<<"Unsolved Sudoku"<<endl; sudoku.print();
	sudoku.solve(); //start solving the sudoku
	cout<<"Solved Sudoku"<<endl; sudoku.print(); //print the sudoku state
}
