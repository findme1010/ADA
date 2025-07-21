#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 10
#define y 100

int count = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *A, int l, int h) {
    int p = A[l];
    int i = l;
    int j = h + 1;

    do {
        do {
            i++;
            count++;
        } while (A[i] < p);

        do {
            j--;
            count++;
        } while (A[j] > p);

        swap(&A[i], &A[j]);
    } while (i < j);
    
    swap(&A[i], &A[j]);
    swap(&A[l], &A[j]);

    return j;
}

void Quicksort(int *A, int l, int h) {
    int s;
    if (l < h) {
        s = partition(A, l, h);
        Quicksort(A, l, s - 1);
        Quicksort(A, s + 1, h);
    }
}

int main() {
    int *A, iter = 1;
    srand(time(NULL));

    FILE *fp1, *fp2, *fp3;

    for (int n = x; n <= y; n += 10) {
        count = 0;
        A = (int *) malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            //A[i] = i + 1;               // Worst case
            //A[i] = rand() % 100;     // Avg case
            A[i] = 3;                // Best case
        }

        fp1 = fopen("a_num.txt", "a");
        fprintf(fp1, "Iteration : %d\n", iter);
        for (int i = 0; i < n; i++) {
            fprintf(fp1, "%d\t", A[i]);
        }
        fprintf(fp1, "\n");

        Quicksort(A, 0, n - 1);

        fp2 = fopen("a_sort.txt", "a");
        fprintf(fp2, "After sorting\n");
        fprintf(fp2, "Iteration : %d\n", iter);
        iter++;
        for (int i = 0; i < n; i++) {
            fprintf(fp2, "%d\t", A[i]);
        }
        fprintf(fp2, "\n");

        fp3 = fopen("best.txt", "a");
        fprintf(fp3, "%d\t%d\n", n, count);

        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }

    return 0;
}
