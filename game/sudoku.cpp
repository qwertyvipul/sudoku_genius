class Sudoku{
	int puzzle[81]; //the puzzle to be dealt with
	ENodeptr eHead; //reference to the empty index list
	public:
		Sudoku(int[]); //constructor to initialize the class with the puzzle
		void solve(); //this will start solving the sudoku
		void print(); //this will print the state of the puzzle at any instance
		void printEmptyIndexes();
		void printProbList();
		ENodeptr getEHead();
};

Sudoku::Sudoku(int puzzle[]){
	cout<<"STEP - 1: Instance of sudoku class created!"<<endl;
	for(int i=0; i<81; i++){
		this->puzzle[i] = puzzle[i]; //copy all the indexes into the sudoku puzzle
	}
	//cout<<"Great! A new Puzzle."<<endl;
}

void Sudoku::solve(){
	cout<<"STEP - 2: sudoku.solve() function called!"<<endl;
	//cout<<"Solving the puzzle..."<<endl;
	//cout<<"Creating the Empty List..."<<endl;
	
	//STEP-3
	this->eHead = createEmptyList(puzzle); //create a list of all the empty indexes
	int flag=1;
	while(flag==1){
		flag=0;
		ENodeptr eNode = this->eHead;
		
		if(eNode->next == NULL){
			this->puzzle[eNode->index] = eNode->plink->value;
			break;
		}
		
		while(eNode!=NULL){
			int probCount = countProb(eNode->plink);
			if(probCount==1){
				this->puzzle[eNode->index] = eNode->plink->value;
				//eNode->prev->next = eNode->next;
				//eNode->next->prev = eNode->prev;
				this->eHead = createEmptyList(this->puzzle);
				eNode = NULL;
				flag=1;
			}else{
				eNode = eNode->next;
			}
		}
		printProbList();
	}
}


void Sudoku::printEmptyIndexes(){
	ENodeptr node;
	node = this->eHead;
	int total=0;
	cout<<"All empty indexes: ";
	while(node != NULL){
		cout<<node->index<<" ";
		total++;
		node = node->next;
	}
	cout<<"\nTotal = "<<total<<endl;
}

void Sudoku::printProbList(){
	ENodeptr node = this->eHead;
	while(node!=NULL){
		cout<<"INDEX = "<<node->index<<" - ";
		PNodeptr pNode = node->plink;
		while(pNode!=NULL){
			cout<<pNode->value<<" ";
			pNode = pNode->next;
		}
		cout<<endl;
		node = node->next;
	}
}

void Sudoku::print(){ //prints the sudoku state at any instance
	cout<<"***********PUZZLE***********"<<endl;
	for(int i=0; i<9; i++){
		if(i%3==0) cout<<"----------------------------"<<endl;
		for(int j=0, temp=i*9; j<9; j++, temp++){
			if(j%3==0){ cout<<"|"; } else{ cout<<" "; }
			cout<<puzzle[temp]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"----------------------------"<<endl;
	cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
}