#include <stdio.h>  
#include <stdlib.h>

int V, E, t[50], l = 0;  
void driver(int[][2]);  // Function to initiate topological sorting.
void dfs(int, int[], int[][2]);  // Depth-first search function for exploring the graph.

int main() {
    int i, j, c, ch;  // Variable declarations for loop counters and choices.
    
    // Prompt user for number of vertices and edges in the graph
    printf("Topological sorting for DIRECTED ACYCLIC GRAPH using DFS method\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &V);  // Read number of vertices
    printf("Enter the number of edges: ");
    scanf("%d", &E);  // Read number of edges
    
    int a[E][2];  // Declare an array to hold edges (pair of vertices)
    
    // Input the edges from the user
    printf("Enter %d pair of edges - \n", E);
    for (i = 0; i < E; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);  // Read each edge
    }

    // Input validation to check for repeated edges and invalid vertex references
    for (i = 0; i < E - 1; i++) {
        for (j = i + 1; j < E; j++) {
            // Check for duplicate edges
            if ((a[i][0] == a[j][0]) && (a[i][1] == a[j][1])) {
                printf("WRONG INPUT! Cannot enter repeated edges, try again. . .\n");
                exit(0);  // Exit if duplicate edge is found
            }
            // Check for invalid vertex references
            if ((0 > a[i][0] || a[i][0] >= V) || (0 > a[i][1] || a[i][1] >= V) || 
                (0 > a[E - 1][0] || a[E - 1][0] >= V) || (0 > a[E - 1][1] || a[E - 1][1] >= V)) {
                printf("WRONG INPUT! Edges having invalid vertex reference . . .\n");
                exit(0);  // Exit if any edge references invalid vertices
            }
            
             if(a[i][0]==a[j][1]) {
                printf("WRONG INPUT! Graph should not contain any cycle . . .\n");
                exit(0);
            } 
        }
    }
    
    // Print the vertices and edges
    printf("Vertices: ");
    for (i = 0; i < V; i++)
        printf("%d  ", i);  // Print all vertices
    printf("\nEdges:\n");
    for (i = 0; i < E; i++)
        printf("%d -> %d\n", a[i][0], a[i][1]);  // Print each edge
    
    printf("The topological order is:\n");
    driver(a);  // Call the driver function to perform topological sorting
    return 0;
}

void driver(int a[E][2]) {
    int visit[10], flag = -1, i, j, k;  // Declare an array to track visited vertices, a flag for cycle detection

    // Initialize all vertices as unvisited
    for (i = 0; i < V; i++) {
        visit[i] = 0;
    }
    
    // Main loop to perform DFS on each unvisited vertex
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            flag = 0;  // Reset flag for cycle detection
            for (j = 0; j < E; j++) {
                if (a[j][1] == i) {  // Check if vertex i has incoming edges
                    flag = 1;  // Set flag if there's an incoming edge
                }
            }
            // If the vertex has no incoming edges and hasn't been visited, perform DFS
            if (flag == 0 && visit[i] == 0) {
                dfs(i, visit, a);  // Perform DFS on vertex i
                t[l++] = i;  // Add the vertex to the topological order
            }
        }
    }
    
    // If the flag is still -1, it means there's a cycle
    if (flag == -1) {
        printf("Graph is not a DAG\n");  // Output if the graph is not a Directed Acyclic Graph
    } else {
        // Print the topological order in reverse
        for (i = V - 1; i >= 0; i--)
            printf("%d  ", t[i]);  // Output the topological order
    }
}

void dfs(int i, int visit[10], int a[E][2]) {
    int j;  // Loop counter
    visit[i] = 1;  // Mark vertex i as visited
    for (j = 0; j < E; j++) {
        // For each edge, if it starts from vertex i and the destination vertex hasn't been visited, continue DFS
        if (a[j][0] == i && visit[a[j][1]] == 0) {
            dfs(a[j][1], visit, a);  // Recur for the destination vertex
            t[l++] = a[j][1];  // Add the destination vertex to the topological order
        }
    }
}

/* Sample Outputs

Example 1:
Input:
Enter the number of vertices: 6
Enter the number of edges: 6
Enter 6 pair of edges - 
5 2
5 0
4 0
4 1
2 3
3 1

Output:
Vertices: 0  1  2  3  4  5  
Edges:
5 -> 2
5 -> 0
4 -> 0
4 -> 1
2 -> 3
3 -> 1
The topological order is:
4  5  2  3  1  0  

Example 2:
Input:
Enter the number of vertices: 4
Enter the number of edges: 5
Enter 5 pair of edges - 
0 1
0 2
1 2
2 3
1 3

Output:
Vertices: 0  1  2  3  
Edges:
0 -> 1
0 -> 2
1 -> 2
2 -> 3
1 -> 3
The topological order is:
0  1  2  3  

Example 3:
Input:
Enter the number of vertices: 4
Enter the number of edges: 4
Enter 4 pair of edges - 
0 1
1 2
2 3
3 1

Output:
Vertices: 0  1  2  3  
Edges:
0 -> 1
1 -> 2
2 -> 3
3 -> 1
Graph is not a DAG

Example 4 :
Input:
Enter the number of vertices: 4
Enter the number of edges: 3
Enter 3 pair of edges - 
0 1
1 4
0 2

Output:
Vertices: 0  1  2  3  
Edges:
0 -> 1
1 -> 4
0 -> 2
WRONG INPUT! Edges having invalid vertex reference . . .
*/
