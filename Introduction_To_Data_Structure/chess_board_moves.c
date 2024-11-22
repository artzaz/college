#include <stdio.h>

#define BOARD_SIZE 64
#define ROW(i) (i / 8)
#define COL(i) (i % 8)

// Function to check if a square is inside the chessboard
int isValidSquare(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

// Convert row and column to index
int toIndex(int row, int col) {
    return row * 8 + col;
}

// Print all possible moves for black pawns
void printBlackPawnMoves(int board[], int pos) {
    int row = ROW(pos), col = COL(pos);

    // Move forward
    if (isValidSquare(row - 1, col) && board[toIndex(row - 1, col)] == 0) {
        printf("Pawn at %d%d moves to %d%d\n", row, col, row - 1, col);
    }
    // Capture diagonally
    if (isValidSquare(row - 1, col - 1) && board[toIndex(row - 1, col - 1)] > 0) {
        printf("Pawn at %d%d captures at %d%d\n", row, col, row - 1, col - 1);
    }
    if (isValidSquare(row - 1, col + 1) && board[toIndex(row - 1, col + 1)] > 0) {
        printf("Pawn at %d%d captures at %d%d\n", row, col, row - 1, col + 1);
    }
}

// Print all possible moves for black knights
void printBlackKnightMoves(int board[], int pos) {
    int row = ROW(pos), col = COL(pos);
    int knightMoves[8][2] = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
        {2,  1}, {1,  2}, {-1,  2}, {-2,  1}
    };

    for (int i = 0; i < 8; i++) {
        int newRow = row + knightMoves[i][0];
        int newCol = col + knightMoves[i][1];
        if (isValidSquare(newRow, newCol)) {
            int target = toIndex(newRow, newCol);
            if (board[target] >= 0) { // Can move to empty or capture white
                printf("Knight at %d%d moves to %d%d\n", row, col, newRow, newCol);
            }
        }
    }
}

// Main function to print all possible moves for black
void printBlackMoves(int board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] < 0) { // If it's a black piece
            switch (board[i]) {
                case -1: // Black Pawn
                    printBlackPawnMoves(board, i);
                    break;
                case -2: // Black Knight
                    printBlackKnightMoves(board, i);
                    break;
                // Add more cases for other black pieces (Bishop, Rook, Queen, King)
            }
        }
    }
}

int main() {
    int chessboard[64] = {
        -4, -2, -3, -5, -6, -3, -2, -4, // Row 8 (Black's back rank)
        -1, -1, -1, -1, -1, -1, -1, -1, // Row 7 (Black's pawns)
         0,  0,  0,  0,  0,  0,  0,  0, // Row 6
         0,  0,  0,  0,  0,  0,  0,  0, // Row 5
         0,  0,  0,  0,  0,  0,  0,  0, // Row 4
         0,  0,  0,  0,  0,  0,  0,  0, // Row 3
         1,  1,  1,  1,  1,  1,  1,  1, // Row 2 (White's pawns)
         4,  2,  3,  5,  6,  3,  2,  4  // Row 1 (White's back rank)
    };

    printf("Black's possible moves:\n");
    printBlackMoves(chessboard);

    return 0;
}
