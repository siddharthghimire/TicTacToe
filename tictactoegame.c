//tictactoe game

#include<stdio.h> 
#include<stdbool.h> //for boolian function

//check winner using the fucntion
bool checkwinner(char board[3][3],char move){
	int i;
		//diagonal check
		if(board[0][0]== move && board[1][1]== move && board[2][2] == move){// left to right diagonal
		return true;
	}
		if(board[0][2]== move && board[1][1]== move && board[2][0] == move){//Right to Left Diagonal
		return true;
	}
	
	for(i=0;i<3;i++){
		//for row check
		if(board[i][0] == move && board[i][1] == move && board[i][2] == move){//Loop runs 3 times to check each row
		return true;
	  }
	}
	for(i=0;i<3;i++){
		//check column win
		if(board[0][i] == move && board[1][i] == move && board[2][i] == move){//Loop runs 3 times to check each column
		return true;
		}
	}
	
	return false;//for no winner
}

//check draw status using bool isdraw function 
bool isdraw(char board[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]== ' '){
			
			return false;
			}//space is left hence game has to go on
		}
	}
	return true;//since no space and no winner is declared, the game is drawn
	
}

int main(){
	char board[3][3] = { //declare and initialize game layout
	{' ', ' ', ' '}, 
	{' ', ' ', ' '}, 
	{' ', ' ', ' '}
    };
	int row,col;
	int i,j;
	char move='X';
	for(i=0;i<9;++i){
			printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);//first row	
			printf("------------\n");
			printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);//second row
			printf("------------\n");
			printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);//third row
	
		
	printf("player %c enter your row and column(0-2) \t",move);
	scanf("%d %d",&row,&col);
	if(row < 0 || row > 2 || col < 0 || col > 2)//since limited number of row and column it cant be less than 0 nor greater than 2
	{
		printf("Invalid Input, Try Again\n");
		i--;
		continue;
		
	}
	if(board[row][col] == ' '){
		board[row][col] = move;//the value of move is stored in row and column given by the user
	}
	else{
		printf("Occupied Space, Invalid Input try again\n");//if the space is occupied the value isnt overwritten hence the user has to input a valid row and column
		i--;
		continue;

}
    if(checkwinner(board,move)==1){
    	printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);//displays first row	with all the records of the game
    	printf("------------\n");
    	printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);//displays Second row	with all the records of the game
    	printf("------------\n");
    	printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);//displays Third row	with all the records of the game
    	printf("Player %c is the winner",move);
    	
    	return 0;//if any winner is declared the game ends here
    	}
    if(isdraw(board)==1){
    	printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);//displays first row	with all the records of the game
    	printf("------------\n");
    	printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);//displays Second row	with all the records of the game
    	printf("------------\n");
    	printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);//displays Third row	with all the records of the game
    	printf("Draw");
    	return 0;//if draw game ends here
	}
    
      move = (move == 'X')?//if the current value of move is X it is changed to O after the completion of first round and vice versa
	         'O' : 
	         'X';
	 }
	return 0;//game ends here
}
