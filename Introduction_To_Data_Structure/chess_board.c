#include <stdio.h>

#define BOARD_SIZE 8

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_position(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

void print_possible_black_moves(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("Possible moves for black pieces:\n");
    
    for(int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            
            if (board[i][j] == 'p') {
                if (is_valid_position(i + 1, j) && board[i + 1][j] == ' ') {
                    printf("Black pawn from (%d,%d) to (%d,%d)\n", i, j, i + 1, j);
                }
                if (is_valid_position(i + 1, j + 1) && (board[i + 1][j - 1] >= 'A' && board[i + 1][j + 1] <= 'Z')) {
                    printf("Black pawn from (%d,%d) captures on (%d,%d)\n", i, j, i + 1, j - 1);
                }
                if (is_valid_position(i + 1, j + 1) && (board[i + 1][j + 1] >= 'A' && board [i + 1 ][j + 1] <= 'Z')) {
                    printf("Black pawn from (%d,%d) captures on (%d,%d)\n", i, j, i + 1, j + 1);
                }
            }
        }
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    };
    
    print_board(board);
    print_possible_black_moves(board);
    
    return 0;
}
