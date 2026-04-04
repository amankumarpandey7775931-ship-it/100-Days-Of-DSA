/* Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void dfs(int node, int adj[MAX][MAX], bool visited[], int n) {
    visited[node] = true;
    printf("%d ", node);
    for (int neighbor = 1; neighbor <= n; neighbor++) {
        if (adj[node][neighbor] && !visited[neighbor]) {
            dfs(neighbor, adj, visited, n);
        }
    }
}

int main() {
    int n, s;
    int adj[MAX][MAX] = {0};
    bool visited[MAX] = {false};

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    scanf("%d", &s);

    dfs(s, adj, visited, n);
    return 0;
}
