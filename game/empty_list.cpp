typedef struct EmptyList{
	int index; //the value of the index
	struct EmptyList* prev;
	struct EmptyList* next; //pointer to the next empty index
	PNodeptr plink; //pointer to the probability list for the index
}ENode;

typedef struct EmptyList* ENodeptr;
#define EBOX (ENodeptr)malloc(sizeof(ENode))


ENodeptr createEmptyList(int puzzle[]){ //create the empty list
	cout<<"STEP - 3: Creating the empty index list"<<endl;
	int flag = 1; //to check if head exists or not
	ENodeptr head, temp;
	for(int index=0; index<81; index++){
		if(puzzle[index]==0){ //if index is 0 i.e it is empty
			//cout<<"INDEX = "<<index<<endl;
			ENodeptr node = EBOX; //create a node for empty list
			node->index = index; //index of the node will be the empty index
			node->next = NULL; //next link is null as for now
	
			//STEP-3.1
			PNodeptr pHead;
			pHead = createProbList(index, puzzle); //create the probabilty list and get the head pointer
			node->plink = pHead; //store the head in the empty list
			
			if(flag){ //if head is not created
				node->prev = NULL;
				head = node; //assign the head will point towards the first node
				flag = 0; //head is created
			}else{
				node->prev = temp;
				temp->next = node; //previous node will point towards the current node
			}
			temp = node; //store the node in temp
		}
	}
	return head; //return the head of the empty list
}