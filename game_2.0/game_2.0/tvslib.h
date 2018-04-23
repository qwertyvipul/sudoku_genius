#ifndef TVSLIB_H
#define TVSLIB_H


//************************************************************//
//ProbList to to store the probable values for given index
typedef struct ProbList { //the probabilty list for each index
	int value; //the probable value
	struct ProbList* prev;
	struct ProbList* next; //points to next value
}PNode;

typedef PNode* PNodeptr;
#define PBOX (PNodeptr)malloc(sizeof(PNode))

PNodeptr createProbList(int index, int puzzle[]);
int countProb(PNodeptr node);
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//


//************************************************************//
//Emptylist to store the all empty index and probability links
typedef struct EmptyList {
	int index; //the value of the index
	struct EmptyList* prev;
	struct EmptyList* next; //pointer to the next empty index
	PNodeptr plink; //pointer to the probability list for the index
}ENode;

typedef ENode* ENodeptr;
#define EBOX (ENodeptr)malloc(sizeof(ENode))
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//



//************************************************************//
//Sudoku class for puzzle empty list and probability map
class Sudoku {
	int puzzle[81]; //the puzzle to be dealt with
	ENodeptr eHead; //reference to the empty index list
	map<int, PNodeptr> pMap;

public:
	Sudoku(int[]); //constructor to initialize the class with the puzzle
	int* getPuzzle();
	map<int, PNodeptr> getMap();

	//functions
	void solve(); //this will start solving the sudoku
	void print(); //this will print the state of the puzzle at any instance
	void printEmptyIndexes();
	void printProbList();
};
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//


//************************************************************//
//CheckIndex to perform the index check for probability of a particular value at the given index
class CheckIndex {
	int value;
	int index;
	int* puzzle;
public:
	CheckIndex(int, int, int*);
	int checkIndex();
	int checkRow();
	int checkCol();
	int checkBox();
};
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

ENodeptr createEmptyList(Sudoku* sudoku);


#endif
