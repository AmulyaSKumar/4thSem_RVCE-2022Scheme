#include <stdio.h>
#include <string.h>

const int MAX = 256;  // Maximum size for the character set

// Function to generate the shift table for the Horspool algorithm
void fnGenShiftTable(char p[], int t[]) {
    int m, i, j;

    m = strlen(p);  // Length of the pattern

    // Initialize the shift table with the length of the pattern
    for (i = 0; i < MAX; i++) {
        t[i] = m;  // Default shift is the length of the pattern
    }

    // Fill in the shift table based on the pattern
    for (j = 0; j < m - 1; j++) {
        t[p[j]] = m - 1 - j;  // Shift based on the last occurrence of each character
    }
}

// Function to perform the Horspool string matching algorithm
int fnHorspool(char s[], char p[], int t[]) {
    int i, n, m, k;

    n = strlen(s);  // Length of the source string
    m = strlen(p);  // Length of the pattern
    i = m - 1;  // Start from the end of the pattern

    // Search for the pattern in the source string
    while (i < n) {
        k = 0;
        // Compare the pattern with the source string from the end
        while ((k < m) && (p[m - 1 - k] == s[i - k])) {
            k++;
        }

        // If the entire pattern matches, return the starting index
        if (k == m)
            return i - m + 1;
        else
            i = i + t[s[i]];  // Shift the index based on the shift table
    }

    return -1;  // Return -1 if the pattern is not found
}

int main() {
    char text[MAX];  // Source string
    char pattern[MAX];  // Pattern string
    int shiftTable[MAX];  // Shift table for the Horspool algorithm
    int found;

    // Input the source string
    puts("Enter the source string: ");
    gets(text);  // Use gets to read the string (consider using fgets for safety)
    // Input the pattern string
    puts("Enter the pattern string: ");
    gets(pattern);  // Use gets to read the string (consider using fgets for safety)
    
    // Generate the shift table for the pattern
    fnGenShiftTable(pattern, shiftTable);
    // Search for the pattern in the source string
    found = fnHorspool(text, pattern, shiftTable);

    // Check if the pattern was found
    if (found == -1)
        puts("\nMatching Substring not found.\n");
    else
        printf("\nMatching Substring found at position: %d\n", found + 1);  // Output position

    return 0;
}

/*
Enter the source string: 
Hello, this is a simple string matching example.
Enter the pattern string: 
string
Matching Substring found at position: 30
*/
