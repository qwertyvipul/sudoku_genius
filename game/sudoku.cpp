#include "empty_list.cpp"
class Sudoku{
	
	int puzzle[81];
	ENodeptr eHead;
	public:
		Sudoku(int[]);
		void solve();
		void print();
};

Sudoku::Sudoku(int puzzle[]){
	for(int i=0; i<81; i++){
		this->puzzle[i] = puzzle[i];
	}
	cout<<"Great! A new Puzzle."<<endl;
}

void Sudoku::solve(){
	cout<<"Solving the puzzle..."<<endl;
	cout<<"Creating the Empty List..."<<endl;
	this->eHead = createEmptyList(puzzle);
	//cout<<"Number of empty indexes: "<<countEmptyIndexes(eHead)<<endl;
}









////////////////////
void Sudoku::print(){
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
