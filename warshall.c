#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int graph[MAX][MAX], count = 0;

// Warshall's Algorithm
void warshall(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                count++;
            }
        }
    }
}

// Plotting function for best and worst case
void plotter(int caseType) {
    FILE *best = fopen("BestW.txt", "a");
    FILE *worst = fopen("WorstW.txt", "a");

    for (int n = 1; n <= 10; n++) {
        // Reset graph
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = 0;

        // Best Case: Sparse graph
        if (caseType == 0) {
            for (int i = 0; i < n - 1; i++)
                graph[i][i + 1] = 1;
            graph[n - 1][0] = 1;  // To make it cyclic
        }
        // Worst Case: Complete graph (except self-loops)
        else {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i != j) graph[i][j] = 1;
        }

        count = 0;
        warshall(n);

        if (caseType == 0)
            fprintf(best, "%d\t%d\n", n, count);
        else
            fprintf(worst, "%d\t%d\n", n, count);
    }

    fclose(best);
    fclose(worst);
}

int main() {
    plotter(0);  // Best case
    plotter(1);  // Worst case
    return 0;
}
