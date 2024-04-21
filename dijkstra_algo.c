#include <stdio.h>

#define MAX_VERTICES 10
#define INF 1000000

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int src, int dest) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < vertices; ++i) {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        int min_dist = INF;
        int min_index;

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_index = v;
            }
        }

        visited[min_index] = 1;

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && graph[min_index][v] && dist[min_index] != INF && dist[min_index] + graph[min_index][v] < dist[v]) {
                dist[v] = dist[min_index] + graph[min_index][v];
            }
        }
    }

    printf("Shortest distance from %d to %d is: %d\n", src, dest, dist[dest]);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source and destination vertices: ");
    scanf("%d %d", &src, &dest);

    dijkstra(graph, vertices, src, dest);

    return 0;
}
