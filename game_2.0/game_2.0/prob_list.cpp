#include<iostream>
#include "tvslib.h"

PNodeptr createProbList(int index, int* puzzle) {
	int flag=1; //check the value probability for the index
	PNodeptr head, temp;

	for (int value = 1; value <= 9; value++) { //check for values 1 to 9
		CheckIndex checkIndex(value, index, puzzle); //create an instance of the check index class

		if (checkIndex.checkIndex()) { //if probable
			PNodeptr node = PBOX; //create probable node
			node->value = value; //value
			node->next = NULL; //next pointer

			if (flag) { //if no head
				node->prev = NULL;
				head = node; //head points to the first node
				flag = 0; //head created
			}
			else {
				node->prev = temp;
				temp->next = node; //previous node points to the current node
			}
			temp = node; //store the node in temp
		}
	}
	return head; //return head pointer
}

int countProb(PNodeptr node) {
	int total = 0;
	while (node != NULL) {
		total++;
		node = node->next;
	}
	return total;
}