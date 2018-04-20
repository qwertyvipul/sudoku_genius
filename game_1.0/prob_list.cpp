typedef struct ProbList{ //the probabilty list for each index
	int value; //the probable value
	struct ProbList* prev;
	struct ProbList* next; //points to next value
}PNode;

typedef struct ProbList* PNodeptr;
#define PBOX (PNodeptr)malloc(sizeof(PNode))

PNodeptr createProbList(int index, int puzzle[81]){
	//cout<<"STEP - 3.1: Creating the probabilty list for index = "<<index<<endl;
	int flag = 1; //check if head created
	int iflag; //check the value probability for the index
	PNodeptr head, temp;
	for(int value=1; value<=9; value++){ //check for values 1 to 9
		iflag = 0; //intitate to zero
		
		//STEP-3.1.1
		iflag = checkIndex(value, index, puzzle); //check the probability of the value
		if(iflag==1){ //if probable
			PNodeptr node = PBOX; //create probable node
			node->value = value; //value
			node->next = NULL; //next pointer
			
			if(flag){ //if no head
				node->prev = NULL;
				head = node; //head points to the first node
				flag = 0; //head created
			}else{
				node->prev = temp;
				temp->next = node; //previous node points to the current node
			}
			temp = node; //store the node in temp
		}
	}
	return head; //return head pointer
}

int countProb(PNodeptr node){
	int total=0;
	while(node!=NULL){
		total++;
		node = node->next;
	}
	return total;
}