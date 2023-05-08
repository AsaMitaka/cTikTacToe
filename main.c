#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SENTINEL -1

void displayBoard(char board[]) {
    for (int i = 0; i < 9; i++) {
        printf("%c ", board[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

bool checkWinner(char board[], char turn) {
    bool winner = false;
    if (board[0] != '-' && board[0] == board[1] && board[1] == board[2]) {
        winner = true;
    }

    if (board[3] != '-' && board[3] == board[4] && board[4] == board[5]) {
        winner = true;
    }

    if (board[6] != '-' && board[6] == board[7] && board[7] == board[8]) {
        winner = true;
    }

    if (board[0] != '-' && board[0] == board[3] && board[3] == board[6]) {
        winner = true;
    }

    if (board[1] != '-' && board[1] == board[4] && board[4] == board[7]) {
        winner = true;
    }

    if (board[2] != '-' && board[2] == board[5] && board[5] == board[8]) {
        winner = true;
    }

    if (board[0] != '-' && board[0] == board[4] && board[4] == board[8]) {
        winner = true;
    }

    if (board[2] != '-' && board[2] == board[4] && board[4] == board[6]) {
        winner = true;
    }

    if (winner) {
        printf("%c Wins!!!\n", turn);
    }

    return winner;
}

bool checkDraw(int turn_count) {
   if (turn_count < 9) {
      return false;
   }
   else {
      return true;
   }
}

void insert(char board[], char *turn) {
    int index;
    printf("Turn of %c. Enter index: ", *turn);
    scanf("%d", &index);
    if (index == SENTINEL) {
        exit(0);
    }
    board[index - 1] = *turn;
}

void switchTurn(char *turn) {
    if (*turn == 'X') { *turn = 'O';}
    else { *turn = 'X';}
}

int main() {
    char board[] = {'-', '-', '-', '-', '-','-', '-', '-', '-'};
    int turn_count = 0;
    char turn = 'X';
    printf("Welcome to Tic Tac Toe!\n");
    printf("To quit the game at any time, enter -1\n");
    printf("Positions are numbered from 1 to 9 (left to right, top to bottom)\n");

    while (true) {
        displayBoard(board);
        insert(board, &turn);
        turn_count++;
        if (checkWinner(board, turn)) {
            displayBoard(board);
            break;
        }
        if (checkDraw(turn_count)) {
            printf("The game is a draw!\n");
            displayBoard(board);
            break;
        }
        switchTurn(&turn);
    }

    return 0;
}

