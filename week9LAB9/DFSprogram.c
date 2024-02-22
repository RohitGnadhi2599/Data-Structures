#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int n, i, j, visited[MAX_VERTICES];
int adj[MAX_VERTICES][MAX_VERTICES];

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
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
    dfs(v);

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("\nThe graph is not connected.\n");
            return 0;
        }
    }

    printf("\nThe graph is connected.\n");

    return 0;
}
