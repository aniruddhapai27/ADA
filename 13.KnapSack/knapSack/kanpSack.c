#include <stdio.h>
#include <stdlib.h>

int p[100]; // profit
int w[100]; // weight
int table[100][100];
int n;        // number of items
int capacity; // sack capacity
int count = 0;

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapSack()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else
            {
                count++;
                if (j < w[i - 1]) // i will be 1, so to get value of 0 also, we have to do i-1
                {
                    table[i][j] = table[i - 1][j];
                }
                else
                {
                    table[i][j] = max(table[i - 1][j], p[i - 1] + table[i - 1][j - w[i - 1]]);
                }
            }
        }
    }
    return table[n][capacity];
}

void tester()
{
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("\nWeight\tProfit\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &w[i], &p[i]);
    }
    printf("Maximum profit is: %d\n", knapSack());

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            printf("%02d ", table[i][j]);
        }
        printf("\n");
    }

    int m = capacity;
    printf("\nComposition\n");
    for (int i = n; i > 0; i--)
    {
        if (table[i][m] != table[i - 1][m])
        {
            printf("%d\t", i);
            m = m - w[i - 1];
        }
    }
}

void plotter()
{
    FILE *f1 = fopen("knap.txt", "w");
    for (int i = 1; i <= 10; i++)
    {
        count = 0;
        n = i * 2;
        capacity = i * 5;
        for (int j = 1; j <= n; j++)
        {
            w[i] = rand() % capacity + 1;
            p[i] = rand() % 50 + 1;
        }
        knapSack();
        fprintf(f1, "%d\t%d\n", n, count);
    }
    fclose(f1);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1- Tester\n2- Plotter\n0- Exit\n");
        printf("Enter choice: ");
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