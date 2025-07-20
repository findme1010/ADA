#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cnt = 0;
int bub(int *a, int n)
{
    int flag = 0, i, j, temp;
    cnt = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            cnt++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    return cnt;
}

int main()
{
    int min, i, j, n, *arr;
    FILE *fp1, *fp2;
    fp1 = fopen("worst_output.txt", "w");
    fp2 = fopen("worst_case.txt", "w");
    srand(time(NULL));
    for (n = 10; n <= 100; n += 10)
    {
        fprintf(fp1, "n= %d\n", n);
        arr = (int *)malloc(n * sizeof(int));
        fprintf(fp1, "Array:\n");

        for (i = 0; i < n; i++)
        {
            // best
            // arr[i] = i + 1;
            // avg
            // arr[i] = rand() % n;
            // worst
            arr[i] = n - i;
            fprintf(fp1, "%d ", arr[i]);
        }
        fprintf(fp1, "\n");
        bub(arr, n);

        fprintf(fp1, "Sorted Array:\n");
        for (int i = 0; i < n; i++)
        {
            fprintf(fp1, "%d ", arr[i]);
        }
        fprintf(fp1, "\n");
        fprintf(fp2, "%d\t%d\n", n, cnt);
    }
    free(arr);
    fclose(fp1);
    fclose(fp2);
    return 0;
}