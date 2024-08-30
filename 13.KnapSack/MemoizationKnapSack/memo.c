#include <stdio.h>
#include <stdlib.h>

int p[100]; // profit
int w[100]; // weight
int dp[100][100];
int n; // number of items
int W; // sack W
int count = 0;

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapSack(int i, int j)
{
    if (dp[i][j] == -1)
    {

        count++;
        if (j < w[i - 1])
        {
            dp[i][j] = knapSack(i - 1, j);
        }
        else
        {
            dp[i][j] = max(knapSack(i - 1, j), p[i - 1] + knapSack(i - 1, j - w[i - 1]));
        }
    }
    return dp[i][j];
}

void createTable(int n, int W)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = -1;
            }
        }
    }
}

void tester()
{
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    printf("\nWeight\tProfit\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &w[i], &p[i]);
    }
    createTable(n, W);
    printf("Maximum profit is: %d\n", knapSack(n, W));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            printf("%02d ", dp[i][j]);
        }
        printf("\n");
    }

    int m = W;
    printf("\nComposition\n");
    for (int i = n; i > 0; i--)
    {
        if (dp[i][m] != dp[i - 1][m])
        {
            printf("%d\t", i);
            m = m - w[i - 1];
        }
    }
}

void plotter()
{
    FILE *f1 = fopen("knap.txt", "w");
    for (int i = 5; i <= 10; i++)
    {
        count = 0;
        n = i;
        W = i * 5;
        for (int j = 0; j <= n; j++)
        {
            w[j] = rand() % 10 + 1;
            p[j] = rand() % 50 + 1;
        }
        createTable(n, W);
        knapSack(n, W);
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