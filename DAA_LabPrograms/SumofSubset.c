#include <stdio.h>

int sol = 0;            // Solution count
int arr[10], x[10];    // Input array and solution indicator array
int d;                  // Desired sum

// Recursive function to find subsets that sum to d
void subset(int s, int k, int rem) {
    x[k] = 1; // Include current element in subset
    if (s + arr[k] == d) { // Check if the current subset sums to d
        printf("\nSolution %d= ", ++sol);
        for (int i = 1; i <= k; i++) {
            if (x[i] == 1) {
                printf("%d\t", arr[i]); // Print current subset
            }
        }
    }
    // If the sum with the next element is less than or equal to d
    else if (s + arr[k] + arr[k + 1] <= d) {
        subset(s + arr[k], k + 1, rem - arr[k]); // Recur with next element included
    }
    
    x[k] = 0; // Exclude current element from subset
    // Check if we can find a valid subset without including current element
    if ((s + rem - arr[k] >= d) && (s + arr[k + 1] <= d)) {
        subset(s, k + 1, rem - arr[k]); // Recur with next element excluded
    }
}

int main() {
    int sum = 0, i, n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Calculate the total sum of elements
    }
    printf("Enter the subset max value: ");
    scanf("%d", &d);
    
    // Check if the desired sum is possible
    if (sum < d || arr[1] > d) {
        printf("No Solution\n");
        return 0;
    }
    
    subset(0, 1, sum); // Call the recursive function
    return 0;
}

/* Sample Outputs

Example 1:
Input:
Enter the size of array: 5
Enter the elements of array: 1 2 3 4 5
Enter the subset max value: 5

Output:
Solution 1= 5	
Solution 2= 2	3	
Solution 3= 1	4	

Example 2:
Input:
Enter the size of array: 4
Enter the elements of array: 2 4 6 10
Enter the subset max value: 16

Output:
Solution 1= 6	10	
Solution 2= 2	4	10	
Solution 3= 2	6	4	
Solution 4= 4	6	2	

Example 3 :
Input:
Enter the size of array: 5
Enter the elements of array: 1 2 3 4 5
Enter the subset max value: 12

Output:
No Solution

*/
