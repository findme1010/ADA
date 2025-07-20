#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int graph[MAX][MAX], exist[MAX][MAX], visited[MAX];
int n, count, component;

void init() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
            exist[i][j] = 0;
        }
    }
}

void DFS(int current, int parent, int *cycle) {
    visited[current] = 1;
    printf("-> %d", current);
    for (int i = 0; i < n; i++) {
        count++;
        if (graph[current][i] == 1) {
            if (visited[i] == 0) {
                DFS(i, current, cycle);
            } else if (i != parent) {
                *cycle = 1;
            }
        }
    }
}

void connectedComponents(int *cycle) {
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            component++;
            printf("Component = %d\n", component);
            DFS(i, -1, cycle);
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));
    int edges, u, v;
    FILE *fp1;
    
    for (int x = 1; x <= 10; x++) {
        int cycle = 0;
        component = 0;
        count = 0;

        init();

    again:
        printf("Enter the number of vertices: ");
        scanf("%d", &n);
        printf("Enter the number of edges: ");
        scanf("%d", &edges);

        if (edges > (n * (n - 1)) / 2) {
            printf("Edges cannot be more than (n*(n-1))/2. Enter the edge again\n");
            goto again;
        }

        // Random edge generator
        for (int i = 0; i < edges; i++) {
            int u = rand() % n;
            int v = rand() % n;
            if (u != v && exist[u][v] == 0 && exist[v][u] == 0) {
                graph[u][v] = graph[v][u] = 1;
                exist[u][v] = exist[v][u] = 1;
                printf("The edge is from %d to %d\n", u, v);
            } else {
                i--;
            }
        }

        printf("Component = %d\n", component);
        DFS(0, -1, &cycle);
        printf("\n");

        int connected = 1;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                connected = 0;
            }
        }

        if (connected) {
            printf("The graph is connected\n");
        } else {
            printf("The graph is not connected and the connected components are:\n");
            connectedComponents(&cycle);
        }

        if (cycle == 1) {
            printf("The graph is cycled\n");
        } else {
            printf("The graph is not cycled\n");
        }

        fp1 = fopen("DFS_output.txt", "a");
        fprintf(fp1, "%d\t%d\n", n, count);
        fclose(fp1);
    }

    return 0;
}
