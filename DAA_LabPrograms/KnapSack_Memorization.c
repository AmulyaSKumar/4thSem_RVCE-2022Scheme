#include <stdio.h>

int w[10], v[10];  // Arrays to store weights and values of items
int n, c;  // Number of items and capacity of the knapsack

// Function to perform the 0/1 Knapsack dynamic programming algorithm
void knapsack(int n, int c, int a[n + 1][c + 1]) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= c; j++) {
            if (a[i][j] < 0) {  // Only calculate if the cell is uninitialized
                if (j < w[i]) {
                    a[i][j] = a[i - 1][j];  // Item cannot be included
                } else {
                    // Maximize value by including or excluding the current item
                    int c1 = a[i - 1][j];  // Value excluding the current item
                    int c2 = v[i] + a[i - 1][j - w[i]];  // Value including the current item
                    a[i][j] = (c1 > c2) ? c1 : c2;  // Choose the maximum value
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);  // Input number of items
    w[0] = 0, v[0] = 0;  // Initialize dummy item

    // Input weights and values of items
    for (int i = 1; i <= n; i++) {
        printf("Enter the weight and value of item-%d: ", i);
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &c);  // Input capacity of the knapsack

    int a[n + 1][c + 1];  // DP table for storing maximum values
    // Initialize the DP table
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= c; j++)
            if (i == 0 || j == 0)
                a[i][j] = 0;  // Base case: 0 items or 0 capacity
            else
                a[i][j] = -1;  // Uninitialized cells

    // Print the initialized DP table
    printf("Initialized DP table:\n");
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= c; y++) {
            printf("%d\t", a[x][y]);  // Print each cell in the table
        }
        printf("\n");
    }

    // Execute the knapsack algorithm
    knapsack(n, c, a);

    // Print the filled DP table
    printf("Filled DP table after calculation:\n");
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= c; y++) {
            printf("%d\t", a[x][y]);  // Print each cell in the table
        }
        printf("\n");
    }

    // Output the maximum value that can be carried in the knapsack
    printf("Output (maximum value in the knapsack) = %d\n", a[n][c]);
    
    return 0;
}

/*
Enter the number of items: 3
Enter the weight and value of item-1: 2 3
Enter the weight and value of item-2: 3 4
Enter the weight and value of item-3: 4 5
Enter the knapsack capacity: 5
Initialized DP table:
0	0	0	0	0	0	
0	-1	-1	-1	-1	-1	
0	-1	-1	-1	-1	-1	
0	-1	-1	-1	-1	-1	
0	-1	-1	-1	-1	-1	
Filled DP table after calculation:
0	0	0	0	0	0	
0	3	3	3	3	3	
0	3	4	4	7	7	
0	3	4	5	7	8	
Output (maximum value in the knapsack) = 7
*/
