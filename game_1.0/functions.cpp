int checkIndex(int value, int index, int puzzle[81]){ //check the probabilty of the value for given index
	int rflag = 0, cflag = 0, bflag = 0;
	rflag = checkRow(value, index, puzzle); //check the row
	cflag = checkCol(value, index, puzzle); //check the column
	bflag = checkBox(value, index, puzzle); //check the box

	if(rflag==1 &&  cflag==1 && bflag==1){
		return 1; //if all row, column and box valid return 1
	}else{
		return 0; //if not return 0
	}
}


int checkRow(int value, int index, int puzzle[]){ //check all columns in a row
	for(int indexcol = index-index%9; indexcol<index-index%9+9; indexcol++){
		if(puzzle[indexcol] == value) return 0; //if same value exists return 0
	}
	return 1; //if value is probable return 1
}


int checkCol(int value, int index, int puzzle[]){ //check all the rows in a column
	for(int indexrow = index%9; indexrow<81; ){
		if(puzzle[indexrow] == value) return 0; //if same value exists return 0
		indexrow+=9;
	}
	return 1; //if value is probable return 1
}


int checkBox(int value, int index, int puzzle[]){ //check the rows and columns in the 3x3 box of the given index
	int indexbox;
	for(int rownum = (index/27)*3; rownum<(index/27)*3+3; rownum++){
		for(int colnum = (index%9)-(index%3); colnum<((index%9)-(index%3))+3; colnum++){
			indexbox = rownum*9 + colnum;
			if(puzzle[indexbox] == value) return 0; //if same value exists return 0
		}
	}
	return 1; //if value is probable return 1
}
