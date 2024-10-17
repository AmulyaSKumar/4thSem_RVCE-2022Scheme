#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to merge two sorted arrays into a final sorted array
int merge(int arr1[], int len1, int arr2[], int len2, int final[]) {
    int i = 0, j = 0, k = 0;
    int count = 0;

    // Merging the two arrays
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            final[k++] = arr1[i++];
        } else {
            final[k++] = arr2[j++];
        }
        count++;
    }
    
    // Adding remaining elements of arr2
    while (j < len2) {
        final[k++] = arr2[j++];
        count++;
    }
    
    // Adding remaining elements of arr1
    while (i < len1) {
        final[k++] = arr1[i++];
        count++;
    }
    
    return count; // Returning the count of operations
}

// Merge sort function that sorts the array
int mergesort(int arr[], int start, int end) {
    if (end - start > 1) {
        int mid = (start + end) / 2;
        int arr1[mid], arr2[end - mid];
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

        // Splitting the array into two halves
        for (int i = 0; i < mid; i++) {
            arr1[i] = arr[i];
        }
        for (int i = 0; i < end - mid; i++) {
            arr2[i] = arr[mid + i];
        }
        
        // Recursively sorting both halves
        c2 = mergesort(arr1, 0, mid);
        c3 = mergesort(arr2, 0, end - mid);
        c4 = merge(arr1, mid, arr2, end - mid, arr); // Merging the sorted halves
        
        return c1 + c2 + c3 + c4; // Total operations
    } else {
        return 0;
    }
}

int main() {
    int choice;
    printf("Select:  1.Sorting\t2.Complexity\n");
    scanf("%d", &choice);
    
    switch (choice) {
    case 1: {
        int n = 5;
        int arr[n];
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter array elements:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        // Sorting the array and counting operations
        int count = mergesort(arr, 0, n);
        printf("Sorted Array:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nTime taken by the program: %d\n", count);
        break;
    }
    case 2: {
        int n, size, j;
        int ln;
        int t1, t2, t3;
        int arr1[32000];
        printf("Enter size of array for complexity calculation of its next 5 multiples: ");
        scanf("%d", &size);
        printf("Size\t\tAscending\tcnlog(n)\t\tDescending\tcnlog(n)\t\tRandom\t\tcnlog(n)\n");

        // Running complexity calculations for different sizes
        for (int i = 0; i < 5; i++, size *= 2) {
            n = size;
            ln = 2 * size * log(size) / log(2);
            
            // Creating an ascending sorted array
            for (j = 0; j < size; j++) {
                arr1[j] = j;
            }
            t1 = mergesort(arr1, 0, size);
            
            // Creating a descending sorted array
            for (j = 0; j < size; j++) {
                arr1[j] = size - j;
            }
            t2 = mergesort(arr1, 0, size);
            
            // Creating a random array
            for (j = 0; j < size; j++) {
                arr1[j] = rand() % 32000;
            }
            t3 = mergesort(arr1, 0, size);
            
            // Printing results
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", 
                   size, t1, ln, t2, ln, t3, ln);
        }
        break;
    }
    default:
        printf("Invalid choice.\n");
        break;
    }

    return 0;
}

/*

Select:  1.Sorting   2.Complexity
1
Enter the size of the array: 5
Enter array elements:
5
3
1
4
2

Sorted Array:
1 2 3 4 5 
Time taken by the program: <operation_count>
*/
