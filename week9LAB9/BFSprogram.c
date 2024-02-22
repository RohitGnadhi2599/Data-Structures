#include <stdio.h>

#define MAX_VERTICES 10

int n, i, j, visited[MAX_VERTICES], queue[MAX_VERTICES], front = 0, rear = 0;
int adj[MAX_VERTICES][MAX_VERTICES];

void bfs(int v) {
    visited[v] = 1;
    queue[rear++] = v;

    while (front < rear) {
        int current = queue[front++];
        printf("%d\t", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter graph data in matrix form:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("\nBFS is not possible. Not all nodes are reachable.\n");
            return 0;
        }
    }

    return 0;
}
