#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 10
#define y 100
#define inc 10
int cnt = 0;
int binary_search(int *arr, int key, int l, int r)
{
    int mid;
    cnt++;
    if (l > r)
        return cnt - 1;
    mid = (l + r) / 2;
    if (arr[mid] == key)
        return cnt;
    else if (key < arr[mid])
        return binary_search(arr, key, l, mid - 1);
    else
        return binary_search(arr, key, mid + 1, r);
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
        printf("n= %d\n", n);
        a = (int *)malloc(n * sizeof(int));
        a[0] = rand() % 10;
        for (i = 1; i < n; i++)
            a[i] = a[i - 1] + (rand() % 100 + 1);
        fprintf(fp1, "n= %d\nArray: ", n);
        for (i = 0; i < n; i++)
        {
            fprintf(fp1, "%d ", a[i]);
        }
        fprintf(fp1, "\n");

        // Best Case
        k = a[(n - 1) / 2];
        cnt = 0;
        res = binary_search(a, k, 0, n - 1);
        fprintf(fp2, "%d\t%d\t", n, cnt);
        printf("Best= %d\n", k);
        fprintf(fp1, "Best key= %d, Comparisons= %d\n", k, cnt);

        // Avarage Case
        k = a[(n - 1) / 4];
        cnt = 0;
        res = binary_search(a, k, 0, n - 1);
        fprintf(fp2, "%d\t", cnt);
        printf("Avg= %d\n", k);
        fprintf(fp1, "Avarage key= %d, Comparisons= %d\n", k, cnt);

        // Worst Case
        k = 999;
        cnt = 0;
        res = binary_search(a, k, 0, n - 1);
        fprintf(fp2, "%d\t\n", cnt);
        printf("Worst= %d\n", k);
        fprintf(fp1, "worst key= %d, Comparisons= %d\n", k, cnt);

        fprintf(fp1, "------------------------------------------------------------------------------------\n");
        free(a);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}