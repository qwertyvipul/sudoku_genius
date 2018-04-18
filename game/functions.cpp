int checkIndex(int value, int index, int puzzle[81]){
	//cout<<"STEP - 3.1.1: VALUE = "<<value<<endl;
	int rflag = 0, cflag = 0, bflag = 0;
	
	//STEP-3.1.2
	rflag = checkRow(value, index, puzzle);
	
	//STEP-3.1.3
	cflag = checkCol(value, index, puzzle);
	
	//STEP-3.1.4
	bflag = checkBox(value, index, puzzle);
	
	if(rflag==1 &&  cflag==1 && bflag==1){
		//cout<<"VALUE VALID"<<endl;
		return 1;
	}else{
		//cout<<"VALUE INVALID"<<endl;
		return 0;
	}
}


int checkRow(int value, int index, int puzzle[]){ //check all columns in a row
	//cout<<"STEP - 3.1.2: CHECKING ROW...\t";
	for(int indexcol = index-index%9; indexcol<index-index%9+9; indexcol++){
		//cout<<indexcol<<" ";
		if(puzzle[indexcol] == value){
			//cout<<"INVALID"<<endl;	
			return 0;
		}
	}
	//cout<<"VALID"<<endl;
	return 1;
}


int checkCol(int value, int index, int puzzle[]){
	//cout<<"STEP - 3.1.3: CHECKING COLUMN...\t";
	for(int indexrow = index%9; indexrow<81; ){
		//cout<<indexrow<<" ";
		if(puzzle[indexrow] == value){
			//cout<<"INVALID"<<endl;	
			return 0;
		}
		indexrow+=9;
	}
	//cout<<"VALID"<<endl;
	return 1;
}


int checkBox(int value, int index, int puzzle[]){
	//cout<<"STEP - 3.1.4: CHECKING BOX...\t";
	int indexbox;
	for(int rownum = (index/27)*3; rownum<(index/27)*3+3; rownum++){
		for(int colnum = (index%9)-(index%3); colnum<((index%9)-(index%3))+3; colnum++){
			indexbox = rownum*9 + colnum;
			//cout<<"row = "<<rownum<<" col = "<<colnum<<" index = "<<indexbox<<endl;
			if(puzzle[indexbox] == value){
				//cout<<"INVALID"<<endl;
				return 0;
			}
		}
	}
	//cout<<"VALID"<<endl;
	return 1;
}