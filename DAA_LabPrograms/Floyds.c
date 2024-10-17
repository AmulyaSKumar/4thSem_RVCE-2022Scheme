#include <stdio.h>

#define INF 999  // Define a large value to represent infinity

int graph[100][100];  // Global variable for the adjacency matrix

// Function implementing the Floyd-Warshall algorithm
void algo(int distance[][100], int v) {
    int k, i, j;
    // Iterate over each vertex and update the shortest path
    for (k = 0; k < v; k++) {
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                // Update the distance between vertex i and j
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

// Function to display the resulting distance matrix
void display(int d[][100], int v) {
    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (d[i][j] == INF) {
                printf("INF\t");  // Print INF for unreachable vertices
            } else {
                printf("%d\t", d[i][j]);  // Print the shortest distance
            }
        }
        printf("\n");
    }
}

int main() {
    int v;
    
    // Input the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);  // Input edge weights
            // If no edge exists, set the distance to INF
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    // Call the Floyd-Warshall algorithm
    algo(graph, v);
    
    // Display the shortest path matrix
    printf("The shortest path matrix is:\n");
    display(graph, v);
    
    return 0;
}

/*
Enter the number of vertices: 4
Enter the adjacency matrix (use 999 for INF):
0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0
The shortest path matrix is:
0   3   5   6   
7   0   2   3   
3   6   0   1   
2   5   7   0
*/
