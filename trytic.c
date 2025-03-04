#include <stdio.h>
#include <conio.h>  
#include <stdlib.h> 

#define SIZE 3

void printBoard(char board[SIZE][SIZE], int X, int Y,char move) {
    system("cls");  
    
    printf("\nUse Arrow Keys to Move, Enter to Place X/O\n");
   
    // Printing the Tic-Tac-Toe layout
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == Y && j == X) {
                printf(" .%c. ", board[i][j]);  // Highlight selected cell
            } else {
                printf("  %c  ", board[i][j]);
            }

            if (j < 2 ) {  // To print columns
                printf("|");
            }
        }
        printf("\n");

        if (i < 2 ) {  // To print rows
            printf("-----|-----|-----\n");
        }
    }
    printf("\nUse Arrow Keys to Navigate Through the Board\n");
}

int checkWinner(char board[SIZE][SIZE], char move) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == move && board[i][1] == move && board[i][2] == move) || 
            (board[0][i] == move && board[1][i] == move && board[2][i] == move)) {
            return 1;//check row and column
        }
    }
    if ((board[0][0] == move && board[1][1] == move && board[2][2] == move) || 
        (board[0][2] == move && board[1][1] == move && board[2][0] == move)) {
        return 1;//check diagonal
    }
    return 0;
}

int isDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')//if empty space is found the game must go on
                return 0;
    return 1;//else we return true as all space are occupied
}

int main() {
    char board[SIZE][SIZE] =
	 { 
	 {' ', ' ', ' '}, 
	 {' ', ' ', ' '}, 
	 {' ', ' ', ' '} 
	 };
    int X = 0, Y = 0, key;
    char move = 'X';

    printBoard(board, X,Y,move);  // Print the board initially

    while (1) {
        key = getch();  // Get keyboard input

        if (key == 224) {  // Arrow key detected(ASCII)
            key = getch();
            if (key == 72 && Y > 0) Y--; // Up
            if (key == 80 && Y < SIZE - 1)Y++; // Down
            if (key == 75 && X > 0) X--; // Left
            if (key == 77 && X < SIZE - 1) X++; // Right
        } 
        else if (key == 13) {  // Enter key to place move
            if (board[Y][X] == ' ') {
                board[Y][X] = move;
                
                if (checkWinner(board, move)) {
                    printBoard(board, X, Y,move);
                    printf("\n?? Player %c wins! ??\n", move);
                    break;
                }

                if (isDraw(board)) {
                    printBoard(board, X,Y,move);
                    printf("\n?? It's a draw!\n");
                    break;
                }

                move = (move == 'X') ? 'O' : 'X';  // Switch turn
            }
        }
        printBoard(board, X, Y,move);  // Print the board after every move
    }
    return 0;
}