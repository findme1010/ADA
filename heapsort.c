#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 10
#define Y 100

int count = 0;

// Bottom-up heap construction
void heap(int *A, int n) {
    int heap, parent, child, p;
    for (int i = n/2 - 1; i >= 0; i--) {
        heap = 0;
        parent = i;
        p = A[parent];

        while ((parent * 2) + 1 <= n - 1) {
            child = (2 * parent) + 1;
            if (child < n - 1) {
                count++;
                if (A[child] < A[child + 1]) {
                    child = child + 1;
                }
            }

            count++;
            if (A[child] <= p) {
                heap = 1;
                break;
            } else {
                A[parent] = A[child];
                parent = child;
            }
        }
        A[parent] = p;
    }
}

// Heapify function used during sorting
void heapify(int *A, int n, int i) {
    int heap = 0, parent = i, child;
    int p = A[parent];

    while ((parent * 2) + 1 <= n - 1) {
        child = (2 * parent) + 1;

        if (child < n - 1) {
            count++;
            if (A[child] < A[child + 1]) {
                child = child + 1;
            }
        }

        count++;
        if (A[child] <= p) {
            heap = 1;
            break;
        } else {
            A[parent] = A[child];
            parent = child;
        }
    }
    A[parent] = p;
}

int main() {
    int i, *A, n;
    srand(time(NULL));

    for (int x = X; x <= Y; x += 10) {
        count = 0;
        n = x;
        A = (int *)malloc(n * sizeof(int));

        for (i = 0; i < n; i++) {
            //A[i] = i + 1;
            A[i] = rand() % 100;
            //A[i] = n - i;
        }

        FILE *fp1 = fopen("H_num.txt", "a");
        fprintf(fp1, "Iteration : %d\n", x);
        for (i = 0; i < n; i++) {
            fprintf(fp1, "%d\t", A[i]);
        }
        fprintf(fp1, "\n");
        fclose(fp1);

        heap(A, n);

        int T = n;
        while (T >= 1) {
            int last = T - 1;
            int temp = A[last];
            A[last] = A[0];
            A[0] = temp;
            T--;
            heapify(A, T, 0);
        }

        FILE *fp2 = fopen("H_sort.txt", "a");
        fprintf(fp2, "Iteration : %d\n", x);
        for (i = 0; i < n; i++) {
            fprintf(fp2, "%d\t", A[i]);
        }
        fprintf(fp2, "\n");
        fclose(fp2);

        FILE *fp3 = fopen("H_avg.txt", "a");
        fprintf(fp3, "%d\t%d\n", n, count);
        fclose(fp3);

        free(A);
    }

    return 0;
}
