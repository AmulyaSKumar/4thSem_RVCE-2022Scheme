#include <stdio.h>

int a[100][100];  // Adjacency matrix to represent the graph
int queue[100], visited[100];  // Arrays for BFS: queue and visited nodes
int front = 0, rear = -1;  // Queue pointers for managing BFS traversal

// BFS function to perform the breadth-first search
void bfs(int s, int v) {
    int i;
    // Explore all the vertices adjacent to the current vertex 's'
    for (i = 1; i <= v; i++) {
        // If there is an edge and the vertex has not been visited
        if (a[s][i] && !visited[i]) {
            queue[++rear] = i;  // Add the vertex to the queue
        }
    }

    // If there are still elements in the queue, process the next one
    if (front <= rear) {
        visited[queue[front]] = 1;  // Mark the vertex as visited
        bfs(++front, v);  // Recursively call BFS on the next vertex in the queue
    }
}

int main() {
    int v, i, j;

    // Input number of vertices in the graph
    printf("Number of vertices: ");
    scanf("%d", &v);

    // Initialize the queue and visited array
    for (i = 1; i <= v; i++) {
        queue[i] = 0;  // Initialize the queue to 0
        visited[i] = 0;  // Mark all vertices as unvisited
    }

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            scanf("%d", &a[i][j]);  // Input the adjacency matrix values
        }
    }

    int start;
    // Input the starting vertex for BFS
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // Mark the starting vertex as visited and begin BFS
    visited[start] = 1;
    bfs(start, v);

    // Count and check if the graph is connected
    int count = 0;
    for (i = 1; i <= v; i++) {
        if (visited[i]) {
            count++;
        }
    }

    // If all vertices are visited, the graph is connected
    if (count == v) {
        printf("Connected\n");
    } else {
        printf("Not Connected\n");
    }

    return 0;
}

/*
Number of vertices: 4
Enter the adjacency matrix:
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
Enter the starting vertex: 1
Connected
*/
