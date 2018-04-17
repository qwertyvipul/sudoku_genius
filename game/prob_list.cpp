typedef struct ProbList{
	int value;
	struct ProbList* next;
}PNode;

typedef struct ProbList* PListptr;
#define PBOX (PListptr)malloc(sizeof(PNode))

PListptr createProbList(int index, int puzzle[]){
	int flag = 1, iflag;
	ProbListptr head, temp;
	for(int i=1; i<=9; i++){
		iflag = 0;
		iflag = checkIndex(index, i, puzzle);
		if(iflag==1){
			ProbListptr node = PBOX;
			node->value = i;
			node->next = NULL;
			
			if(flag){
				head = node;
				flag = 0;
			}else{
				temp->next = node;
			}
			temp = node;
		}
	}
}
