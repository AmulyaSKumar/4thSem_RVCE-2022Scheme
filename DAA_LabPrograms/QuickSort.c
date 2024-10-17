#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to partition the array for QuickSort
int partition(int arr[], int start, int end, int *count) {
    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (i <= end && arr[i] <= pivot) {
            i++;
            (*count)++;
        }
        while (j > start && arr[j] > pivot) {
            j--;
            (*count)++;
        }
        if (i < j) {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap pivot with arr[j]
    int temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;

    return j; // Return the pivot index
}

// Recursive QuickSort function
int quicksort(int arr[], int start, int end) {
    if (start < end) {
        int count = 0;
        int p = partition(arr, start, end, &count); // Partition the array

        int c1 = quicksort(arr, start, p - 1); // Sort left partition
        int c2 = quicksort(arr, p + 1, end); // Sort right partition
        return c1 + c2 + count; // Return total comparisons
    }
    return 0; // No comparisons if the partition is invalid
}

int main() {
    int choice;
    printf("Select:  1.Sorting\t2.Complexity\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            int n;
            printf("Enter the size of array: ");
            scanf("%d", &n);
            int arr[n]; // Declare array based on user input
            
            printf("Enter array elements:\n");
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }

            int count = quicksort(arr, 0, n - 1); // Sort the array
            printf("Sorted Array:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\nTotal comparisons: %d\n", count); // Output the number of comparisons
            break;
        }
        
        case 2: {
            int size;
            printf("Enter size of array for complexity calculation: ");
            scanf("%d", &size);
            printf("Size\t\tAscending\tComparisons\tDescending\tComparisons\tRandom\t\tComparisons\n");

            for (int i = 0; i < 5; i++, size *= 2) {
                int arr1[32000];
                int ln2 = size * size; // O(n^2) complexity for descending
                int ln = size * log(size) / log(2); // O(n log n) complexity

                // Test ascending order
                for (int j = 0; j < size; j++) {
                    arr1[j] = j;
                }
                int t1 = quicksort(arr1, 0, size - 1);

                // Test descending order
                for (int j = 0; j < size; j++) {
                    arr1[j] = size - j; // Fill in descending order
                }
                int t2 = quicksort(arr1, 0, size - 1);

                // Test random order
                for (int j = 0; j < size; j++) {
                    arr1[j] = rand() % 32000; // Fill with random numbers
                }
                int t3 = quicksort(arr1, 0, size - 1);

                // Output results
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", size, t1, ln2, t2, ln2, t3, ln);
            }
            break;
        }
        
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    return 0;
}
