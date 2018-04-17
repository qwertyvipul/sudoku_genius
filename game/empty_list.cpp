#include "prob_list.cpp"
typedef struct EmptyList{
	int index;
	struct EmptyList* next;
	PListptr plink;
}ENode;

typedef struct EmptyList* ENodeptr;
#define EBOX (ENodeptr)malloc(sizeof(ENode))


ENodeptr createEmptyList(int puzzle[]){
	int flag = 1;
	ENodeptr head, temp;
	for(int i=0; i<81; i++){
		if(puzzle[i]==0){
			ENodeptr node = EBOX;
			node->index = i;
			node->next = NULL;
	
			phead = createProbList(i, puzzle);
			node->plink = phead;
			
			if(flag){
				head = node;
				flag = 0;
			}else{
				temp->next = node;
			}
			temp = node;
		}
	}
	return head;
}

int countEmptyIndexes(ENodeptr node){
	int total=0;
	while(node != NULL){
		total++;
		cout<<node->index/9+1<<" - "<<node->index%9+1<<endl;
		node = node->next;
	}
	return total;
}
