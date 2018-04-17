void checkIndex(int index, int value, int puzzle[]){
	int rflag = 0, cflag = 0, bflag = 0;
	rflag = checkRow(index, puzzle);
	cflag = checkCol(index, puzzle);
	bflag = checkBox(index, puzzle);
	
	if(rflag==1 &&  cflag==1 && bflag==1){
		return 1;
	}else{
		return 0;
	}
}


void checkRow(int index, int value, int puzzle[]){
	for(int i = index-index%9; i<index-index%9+9; i++){
		if(puzzle[i] == value) return 0;
	}
	return 1;
}


void checkCol(int index, int value, int puzzle[]){
	for(int i = index%9; i<81; i+9){
		if(puzzle[i] == value) return 0;
	}
	return 1;
}


void checkBox(int index, int value, int puzzle[]){
	for(int i = 
}
