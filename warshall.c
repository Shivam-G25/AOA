#include <stdio.h>
#include <limits.h>

#define V 4  


void floydWarshall(int graph[V][V]) {
    int dist[V][V], i, j, k;

    
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0;  
            } else if (graph[i][j] == 0) {
                dist[i][j] = INT_MAX;  
            } else {
                dist[i][j] = graph[i][j];  
            }
        }
    }

    
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    
    printf("The shortest distance matrix is:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");  
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V];
    int i, j;

    
    printf("Enter the graph as an adjacency matrix (enter 0 for no direct path between nodes):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i == j) {
                graph[i][j] = 0;  
            } else {
                printf("Enter weight for edge (%d -> %d) (enter 0 if no direct path): ", i, j);
                scanf("%d", &graph[i][j]);
                if (graph[i][j] == 0) {
                    graph[i][j] = INT_MAX; 
                }
            }
        }
    }

    
    floydWarshall(graph);

    return 0;
}