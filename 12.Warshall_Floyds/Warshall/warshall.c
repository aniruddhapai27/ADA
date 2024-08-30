#include <stdio.h>
#include <stdlib.h>

int count = 0;

void warshall(int graph[100][100], int n)
{
    count = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[i][k] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    count++;
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                }
            }
        }
    }
}

void tester()
{
    int n;
    printf("No. of vertices: ");
    scanf("%d", &n);
    int graph[100][100];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    warshall(graph, n);

    printf("Transitive closure is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void plotter()
{
    FILE *f1, *f2;
    f1 = fopen("best.txt", "w");
    f2 = fopen("worst.txt", "w");

    int graph[100][100];
    // best case
    for (int m = 1; m <= 10; m++)
    {
        int n = m;
        // best case
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = 0;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            graph[i][i + 1] = 1;
        }
        graph[n - 1][0] = 1;
        warshall(graph, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // worst case
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    graph[i][j] = 1;
                }
                else
                {
                    graph[i][j] = 0;
                }
            }
        }
        warshall(graph, n);
        fprintf(f2, "%d\t%d\n", n, count);
    }
    fclose(f1);
    fclose(f2);
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