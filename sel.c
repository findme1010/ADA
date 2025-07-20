#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int min, i, j, n, *arr, temp, cnt = 0;
    FILE *fp1, *fp2;
    fp1 = fopen("output.txt", "w");
    fp2 = fopen("analysis.txt", "w");
    srand(time(NULL));
    for (n = 10; n <= 100; n += 10)
    {
        fprintf(fp1, "n= %d\n", n);
        arr = (int *)malloc(n * sizeof(int));
        fprintf(fp1, "Array:\n");
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
            fprintf(fp1, "%d ", arr[i]);
        }
        fprintf(fp1, "\n");
        // best case, worst case and average case
        cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < n; j++)
            {
                cnt++;
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            if (min != i)
            {
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
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