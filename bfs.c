#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int graph[MAX][MAX], exist[MAX][MAX], visited[MAX], Queue[MAX], parent[MAX];
int F, R, n, count, component, cycle;

void init() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = exist[i][j] = 0;
        }
    }

F=0,R=0;
parent[0]=-1;Queue[R++]=0;cycle=0;count=0;
component=1;
}
void BFS(int current, int *cycle) {
    if (F < R) {
        visited[current] = 1;
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            count++;
            if (graph[current][i]) {
                if (visited[i] == 0) {
                    Queue[R++] = i;
                    visited[i] = 1;
                    parent[i] = current;
                } else if (i != parent[current]) {
                    *cycle = 1;
                }
            }
        }

        BFS(Queue[++F], cycle);
    }
}

void connected_components() {
    F = 0;
    R = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            component++;
            printf("Component - %d:\n", component);
            Queue[R++] = i;
            BFS(i, &cycle);
            printf("\n");
        }
    }
}

int main() {
    int edges, u, v;
    srand(time(NULL));
    FILE *fp1;

    for (int x = 1; x <= 10; x++) {
        init();

        printf("Enter the number of vertices:\n");
        scanf("%d", &n);

    again:
        printf("Enter the number of edges:\n");
        scanf("%d", &edges);

        if (edges > n * (n - 1) / 2) {
            printf("Edges cannot be more than n(n-1)/2. Enter again!\n");
            goto again;
        }

        /*
        for (int i = 0; i < edges; i++) {
            printf("Enter the edge (u - initial vertex and v - final vertex):\n");
            scanf("%d %d", &u, &v);
            graph[u][v] = graph[v][u] = 1;
        }
        */

        for (int i = 0; i < edges; i++) {
            u = rand() % n;
            v = rand() % n;

            if (u != v && exist[u][v] == 0 && exist[v][u] == 0) {
                graph[u][v] = graph[v][u] = 1;
                exist[u][v] = exist[v][u] = 1;
                printf("The edge is from %d to %d\n", u, v);
            } else {
                i--;
            }
        }

        printf("Components - %d:\n", component);
        BFS(0, &cycle);
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
            connected_components();
        }

        if (cycle) {
            printf("The graph is cyclic\n");
        } else {
            printf("The graph is not cyclic\n");
        }

        fp1 = fopen("BFS_output", "a");
        fprintf(fp1, "%d\t%d\n", n, count);
        fclose(fp1);
    }

    return 0;
}