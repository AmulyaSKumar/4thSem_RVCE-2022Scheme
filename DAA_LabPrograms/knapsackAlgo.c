#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, w;

    // Take input for the number of items and the knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &w);

    int weight[n], profit[n]; // Declare arrays for weights and profits based on user input

    // Input weights and profits for each item
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weight[i]);
        printf("Profit of item %d: ", i + 1);
        scanf("%d", &profit[i]);
    }

    // Create the DP table for storing maximum profits
    int table[n + 1][w + 1]; 
    int i, j;

    // Fill the table using dynamic programming
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;  // Base case: no items or zero capacity
            } else if (j - weight[i - 1] < 0) {
                table[i][j] = table[i - 1][j];  // Cannot include the item
            } else {
                // Choose the maximum between including and excluding the item
                table[i][j] = max(table[i - 1][j], profit[i - 1] + table[i - 1][j - weight[i - 1]]);
            }
        }
    }

    // Output the maximum profit that can be obtained
    printf("Maximum Profit: %d\n", table[n][w]);
    return 0;
}

/*
Enter the number of items: 3
Enter the capacity of the knapsack: 5
Weight of item 1: 2
Profit of item 1: 3
Weight of item 2: 3
Profit of item 2: 4
Weight of item 3: 4
Profit of item 3: 5
Maximum Profit: 7
*/
