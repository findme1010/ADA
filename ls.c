#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 10
#define y 100
#define inc 10

int cnt = 0;

int linear_search(int *arr, int key, int n)
{
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt++;
        if (arr[i] == key)
            return cnt; // Key found
    }
    return cnt; // Key not found (worst case)
}

int main()
{
    int i, n, k, *a, res;
    FILE *fp1, *fp2;

    srand(time(0));
    fp1 = fopen("output.txt", "w");
    fp2 = fopen("analysis.txt", "w");

    for (n = x; n <= y; n += inc)
    {
        printf("n = %d\n", n);
        a = (int *)malloc(n * sizeof(int));

        // Generate strictly increasing array
        a[0] = rand() % 10;
        for (i = 1; i < n; i++)
            a[i] = a[i - 1] + (rand() % 100 + 1);

        fprintf(fp1, "n = %d\nArray: ", n);
        for (i = 0; i < n; i++)
        {
            fprintf(fp1, "%d ", a[i]);
        }
        fprintf(fp1, "\n");

        // Best Case - key is at the beginning
        k = a[0];
        res = linear_search(a, k, n);
        fprintf(fp2, "%d\t%d\t", n, cnt);
        printf("Best = %d\n", k);
        fprintf(fp1, "Best key = %d, Comparisons = %d\n", k, cnt);

        // Average Case - key is somewhere in the middle
        k = a[n / 2];
        res = linear_search(a, k, n);
        fprintf(fp2, "%d\t", cnt);
        printf("Avg = %d\n", k);
        fprintf(fp1, "Average key = %d, Comparisons = %d\n", k, cnt);

        // Worst Case - key is not present
        k = 99999;
        res = linear_search(a, k, n);
        fprintf(fp2, "%d\n", cnt);
        printf("Worst = %d\n", k);
        fprintf(fp1, "Worst key = %d, Comparisons = %d\n", k, cnt);

        fprintf(fp1, "------------------------------------------------------------------------------------\n");
        free(a);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
