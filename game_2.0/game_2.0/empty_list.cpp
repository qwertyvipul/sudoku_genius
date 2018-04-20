#include<iostream>
#include "tvslib.h"
#include<map>

using namespace std;

//create empty list
ENodeptr createEmptyList(Sudoku* sudoku) {
	int flag = 1; //to check if head exists or not
	int* puzzle = sudoku->getPuzzle(); //get the sudoku puzzle
	map<int, PNodeptr> pMap = sudoku->getMap(); //get he probability map
	ENodeptr head, temp;

	for (int index = 0; index<81; index++) {
		if (puzzle[index] == 0) { //if index is 0 i.e it is empty
			ENodeptr node = EBOX; //create a node for empty list
			node->index = index; //index of the node will be the empty index
			node->next = NULL; //next link is null as for now

			PNodeptr pHead;//create a probability list
			pHead = createProbList(index, puzzle); //get the head pointer
			node->plink = pHead; //store the head in the empty list
			pMap[index] = pHead; //update the probability map

			if (flag) { //if head is not created
				node->prev = NULL;
				head = node; //assign the head will point towards the first node
				flag = 0; //head is created
			}
			else {
				node->prev = temp;
				temp->next = node; //previous node will point towards the current node
			}
			temp = node; //store the node in temp
		}
	}
	return head; //return the head of the empty list
}
