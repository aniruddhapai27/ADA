#include <stdio.h>

int count;

int Euclid(int m, int n)
{
    count = 0;
    while (n != 0)
    {
        int rem = m % n;
        m = n;
        n = rem;
        count++;
    }

    return m;
}

int consecInteger(int m, int n)
{
    count = 0;
    int min = m > n ? m : n;
    while (min > 0)
    {
        count++;
        if (m % min == 0)
        {
            count++;
            if (n % min == 0)
            {
                break;
            }
        }
        min--;
    }
    return min;
}

int modifiedEuclid(int m, int n)
{
    count = 0;
    while (++count && m != n)
    {
        if (m > n)
        {
            m -= n;
        }
        else
        {
            n -= m;
        }
    }

    return m;
}

void tester()
{
    int choice;
    int m, n;
    int gcd;

    printf("\n1-Euclid\n2-Consecutive Integer\n3-Modified Euclid\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter m and n: \n");
    scanf("%d%d", &m, &n);
    switch (choice)
    {
    case 1:
        gcd = Euclid(m, n);
        break;
    case 2:
        gcd = consecInteger(m, n);
        break;
    case 3:
        gcd = modifiedEuclid(m, n);
        break;
    }

    printf("GCD is: %d\n", gcd);
}

void plotter()
{
    FILE *f1 = fopen("euclidBest.txt", "w");
    FILE *f2 = fopen("euclidWorst.txt", "w");

    FILE *f3 = fopen("consecBest.txt", "w");
    FILE *f4 = fopen("consecWorst.txt", "w");

    FILE *f5 = fopen("modifiedBest.txt", "w");
    FILE *f6 = fopen("modifiedWorst.txt", "w");

    int min, max;
    for (int i = 10; i <= 100; i += 10)
    {
        min = 99999, max = 0;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                Euclid(j, k);
                if (count > max)
                {
                    max = count;
                }
                if (count < min)
                {
                    min = count;
                }
            }
        }
        fprintf(f1, "%d\t%d\n", i, min);
        fprintf(f2, "%d\t%d\n", i, max);

        min = 99999, max = 0;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                consecInteger(j, k);
                if (count > max)
                {
                    max = count;
                }
                if (count < min)
                {
                    min = count;
                }
            }
        }
        fprintf(f3, "%d\t%d\n", i, min);
        fprintf(f4, "%d\t%d\n", i, max);

        min = 99999, max = 0;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                modifiedEuclid(j, k);
                if (count > max)
                {
                    max = count;
                }
                if (count < min)
                {
                    min = count;
                }
            }
        }
        fprintf(f5, "%d\t%d\n", i, min);
        fprintf(f6, "%d\t%d\n", i, max);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1-Tester\n2-Plotter\n0-Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            tester();
            break;
        case 2:
            plotter();
            break;
        default:
            return 0;
        }
    }
}