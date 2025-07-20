#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 // Max input length

int main()
{
    int numCases, i;

    printf("Enter the number of test cases: ");
    scanf("%d", &numCases);
    getchar(); // consume newline

    for (i = 0; i < numCases; i++)
    {
        int cnt = 0, found = 0;
        int n, m, j, k;

        char *text = (char *)malloc(MAX * sizeof(char));
        char *pattern = (char *)malloc(MAX * sizeof(char));

        printf("\n--- Test Case %d ---\n", i + 1);

        // Read text
        printf("Enter the text: ");
        fgets(text, MAX, stdin);
        text[strcspn(text, "\n")] = '\0'; // Remove newline
        n = strlen(text);

        // Read pattern
        printf("Enter the pattern: ");
        fgets(pattern, MAX, stdin);
        pattern[strcspn(pattern, "\n")] = '\0'; // Remove newline
        m = strlen(pattern);

        // Brute force search
        for (j = 0; j <= n - m; j++)
        {
            k = 0;
            while (k < m)
            {
                cnt++; // Count comparisons
                if (text[j + k] != pattern[k])
                    break;
                k++;
            }
            if (k == m)
            {
                printf("Pattern found at index %d\n", j);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("Pattern not found\n");
        }

        printf("Total character comparisons (cnt) = %d\n", cnt);

        free(text);
        free(pattern);
    }

    return 0;
}
