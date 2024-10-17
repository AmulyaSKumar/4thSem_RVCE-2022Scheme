#include<stdio.h>

#define inf 999  // Define 'inf' as a large value representing infinity

int dist[10], visit[10];  // Arrays to store distances and visited status
int v;  // Number of vertices

// Function to perform Dijkstra's algorithm
void dijik(int source, int cost[10][10]) {
    int i, j, u, min;
    
    visit[source] = 1;  // Mark the source vertex as visited
    dist[source] = 0;   // Distance to the source is always 0

    // Loop to find the shortest path to all vertices
    for (i = 1; i <= v; i++) {
        min = inf;

        // Find the unvisited vertex with the minimum distance
        for (j = 1; j <= v; j++) {
            if (visit[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visit[u] = 1;  // Mark the chosen vertex as visited

        // Update the distance to adjacent vertices
        for (j = 1; j <= v; j++) {
            if (dist[j] > dist[u] + cost[u][j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }
}

int main() {
    int i, j;

    // Input the number of vertices
    printf("Vertices: ");
    scanf("%d", &v);

    // Input the cost matrix
    printf("Enter the cost matrix\n");
    int cost[10][10];  // Cost matrix for up to 10 vertices
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            scanf("%d", &cost[i][j]);  // Input each cost
            if (cost[i][j] == 0 && i != j) { 
                cost[i][j] = inf;  // Set cost to 'inf' for non-adjacent vertices
            }
        }
    }

    // Input the source vertex
    printf("Enter the source vertex: ");
    int source;
    scanf("%d", &source);

    // Initialize distances and visited array
    for (i = 1; i <= v; i++) {
        dist[i] = cost[source][i];
        visit[i] = 0;
    }

    // Call Dijkstra's algorithm
    dijik(source, cost);

    // Output the shortest distances from the source to each vertex
    printf("Shortest distances from vertex %d:\n", source);
    for (i = 1; i <= v; i++) {
        if (dist[i] == inf) {
            printf("%d -> %d = Infinity\n", source, i);
        } else {
            printf("%d -> %d = %d\n", source, i, dist[i]);
        }
    }

    return 0;
}
/*
Vertices: 4
Enter the cost matrix
0 10 0 30
10 0 50 0
0 50 0 20
30 0 20 0
Enter the source vertex: 1
Shortest distances from vertex 1:
1 -> 1 = 0
1 -> 2 = 10
1 -> 3 = 50
1 -> 4 = 30*/