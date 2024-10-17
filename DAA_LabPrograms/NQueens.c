#include <stdio.h>
#include <stdlib.h>

int board[20][20]; // Chessboard representation
int sol = 0; // Solution counter

// Function to check if it's safe to place a queen at (row, col)
int place(int row, int col, int n) {
    int i, j;

    // Check this column on upper rows
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return 0; // Column conflict
        }
    }
    
    // Check upper left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0; // Left diagonal conflict
        }
    }
    
    // Check upper right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return 0; // Right diagonal conflict
        }
    }
    
    return 1; // Safe to place the queen
}

// Recursive function to solve the N-Queens problem
void NQueen(int row, int n) {
    int col;

    // All queens are placed successfully
    if (row == n) {
        printf("Solution %d:\n", ++sol);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d\t", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    // Try placing a queen in each column of the current row
    for (col = 0; col < n; col++) {
        if (place(row, col, n)) {
            board[row][col] = 1; // Place queen
            NQueen(row + 1, n); // Move to the next row
            board[row][col] = 0; // Backtrack
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    
    if (n == 3 || n == 2 || n == 0) {
        printf("No solutions exist for %d queens.\n", n);
    } else {
        NQueen(0, n); // Start solving from the first row
    }

    return 0;
}
/*
Enter the number of queens: 4
Solution 1:
1	0	0	0	
0	0	1	0	
0	0	0	1	
0	1	0	0	

Solution 2:
0	1	0	0	
0	0	0	1	
1	0	0	0	
0	0	1	0	
*/