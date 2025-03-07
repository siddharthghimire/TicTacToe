#include <stdio.h>
#include <conio.h>
#include <dos.h> // Needed for bioskey()
void printBoard(char board[3][3], int X, int Y, char move) {
	int i,j;
    system("cls");  // Use Turbo C's screen clear function
    printf("Player %c's Turn\n", move);
    printf("\nUse Arrow Keys to Move, Enter to Place X/O\n\n");

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (i == Y && j == X) {
                cprintf(" .%c. ", board[i][j]);  // navigation
            } else {
		printf("  %c  ", board[i][j]);
	    }
	    if (j < 2) {
		printf("|");
	    }
	}
	printf("\n");

	if (i < 2) {
	    printf("-----|-----|-----\n");
        }
    }
    printf("\nUse Arrow Keys to Navigate Through the Board\n");
}

int checkWinner(char board[3][3], char move) {
	int i;
    for (i = 0; i < 3; i++) {
        if ((board[i][0] == move && board[i][1] == move && board[i][2] == move) || 
            (board[0][i] == move && board[1][i] == move && board[2][i] == move)) {
            return 1;
        }
    }
    if ((board[0][0] == move && board[1][1] == move && board[2][2] == move) || 
        (board[0][2] == move && board[1][1] == move && board[2][0] == move)) {
        return 1;
    }
    return 0;
}

int isDraw(char board[3][3]) {
	int i,j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (board[i][j] == ' '){ // The game must go on
                return 0;
               }
             }
           }
    return 1;//or end it
}

int main() {
    char board[3][3] =
        { 
            {' ', ' ', ' '}, 
            {' ', ' ', ' '}, 
            {' ', ' ', ' '} 
        };
    int X = 0, Y = 0, key;
    char move = 'X';

    printBoard(board, X, Y, move);

    while (1) {
        key = bioskey(0);  // Use BIOS key function for Turbo C

        if (key == 0x4800 && Y > 0) Y--; // Up Arrow
        if (key == 0x5000 && Y < 2) Y++; // Down Arrow
        if (key == 0x4B00 && X > 0) X--; // Left Arrow
        if (key == 0x4D00 && X < 2) X++; // Right Arrow

	else if ((key&0xFF)==13) {  // Enter key
	    if (board[Y][X] == ' ') {
                board[Y][X] = move;

                if (checkWinner(board, move)) {
                    printBoard(board, X, Y, move);
                    printf("\n Player %c wins! \n", move);
                    break;
                }

                if (isDraw(board)) {
                    printBoard(board, X, Y, move);
                    printf("\n It's a draw!\n");
                    break;
                }

                move = (move == 'X') ? 'O' : 'X'; // Switch turn
            }
        }
        printBoard(board, X, Y, move);
    }
    return 0;
}
