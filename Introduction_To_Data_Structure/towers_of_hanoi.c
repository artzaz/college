#include <stdio.h>
#include <math.h>

// Function to print a move
void moveDisk(char from, char to) {
    printf("Move disk from %c to %c\n", from, to);
}

// Function to solve Towers of Hanoi iteratively
void hanoiIterative(int numDisks, char source, char auxiliary, char destination) {
    int totalMoves = pow(2, numDisks) - 1; // Total number of moves
    char towers[3] = {source, destination, auxiliary}; // Tower labels

    // Adjust tower order if number of disks is even
    if (numDisks % 2 == 0) {
        char temp = towers[1];
        towers[1] = towers[2];
        towers[2] = temp;
    }

    for (int move = 1; move <= totalMoves; move++) {
        if (move % 2 == 1) {
            // Odd move: Move the smallest disk
            int from = (move / 2) % 3;
            int to = (from + 1) % 3;
            moveDisk(towers[from], towers[to]);
        } else {
            // Even move: Move a disk that is not the smallest
            int from, to;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i != j) {
                        // Valid move is the one that doesn't involve the smallest disk
                        from = i;
                        to = j;
                    }
                }
            }
            moveDisk(towers[from], towers[to]);
        }
    }
}

int main() {
    int numDisks;

    // Input number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Solve the Towers of Hanoi problem iteratively
    hanoiIterative(numDisks, 'A', 'B', 'C');

    return 0;
}
