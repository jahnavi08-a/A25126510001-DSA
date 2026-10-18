
#include <stdio.h>
#define INF 99999
int main() {
    int cost[20][20], dist[20], visited[20] = {0};
    int n, src, i, j, u, min;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weighted adjacency matrix (0 = no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);
    for (i = 0; i < n; i++)
        dist[i] = cost[src][i];
    dist[src] = 0;
    visited[src] = 1;
    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;
        for (j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        if (u == -1)
            break;
        visited[u] = 1;
        for (j = 0; j < n; j++)
            if (!visited[j] && cost[u][j] != INF &&
                dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
    }
    printf("\nShortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("To vertex %d = Unreachable\n", i);
        else
            printf("To vertex %d = %d\n", i, dist[i]);
    }
    return 0;
}
