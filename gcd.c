#include <stdio.h>
#include <stdlib.h>

void main() {
    int a, b, m, n, count1 = 0, count2 = 0, count3 = 0, i, t, rem;
    FILE *fp1;

    fp1 = fopen("GCD_b.txt", "w");

    for (i = 1; i <= 10; i++) {
        printf("Enter two non-negative integers:\n");
        scanf("%d %d", &a, &b);

        // Euclid's Algorithm (modulus-based)
        m = a;
        n = b;
        count1 = 0;
        while (n != 0) {
            count1++;
            rem = m % n;
            m = n;
            n = rem;
        }

        fprintf(fp1, "%d\t%d\t", i, count1);

        // Subtraction method
        count2 = 0;
        m = a;
        n = b;
        while (m != n) {
            count2++;
            if (m > n)
                m = m - n;
            else
                n = n - m;
        }

        fprintf(fp1, "%d\t", count2);

        // Consecutive Integer Checking Method
        count3 = 0;
        m = a;
        n = b;
        if (m > n)
            t = n;
        else
            t = m;

        while (t >= 1) {
            count3++;
            if (m % t == 0) {
                count3++;
                if (n % t == 0)
                    break;
            }
            t = t - 1;
        }

        fprintf(fp1, "%d\n", count3);
    }

    fclose(fp1);
}
