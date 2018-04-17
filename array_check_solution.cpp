//x-index = index/3
//y-index = index/9


#include<iostream>
using namespace std;


void checkSol(int solution[81]){
	for(int i=0; i<9; i++){ //row
		for(int j=1; j<=9; j++){ //col
			int flag = 0;
			for(int k=i*9; k<=i*9+9; k++){
				if(solution[k] == j){
					flag = 1;
				}
			}
			if(flag == 0) cout<<"Invalid Solution\n";
		}
	}
	cout<<"Correct Solution";
}

int main(){
	int solution[] = {
		1, 7, 5, 2, 9, 4, 8, 3, 6,
		6, 2, 3, 1, 8, 7, 9, 4, 5,
		8, 9, 4, 5, 6, 3, 2, 7, 1,
		5, 1, 9, 7, 3, 2, 4, 6, 8,
		3, 4, 7, 8, 5, 6, 1, 2, 9,
		2, 8, 6, 9, 4, 1, 7, 5, 3,
		9, 3, 8, 4, 2, 5, 6, 1, 7,
		4, 6, 1, 3, 7, 9, 5, 8, 2,
		7, 5, 2, 6, 1, 8, 3, 9, 4
	};
	
	checkSol(solution);
}
