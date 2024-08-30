#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int count = 0;
int dist[100][100];

void floyds(int graph[100][100], int n)
{
    count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == -1)
            {
                dist[i][j] = INT_MAX;
            }
            else
            {
                dist[i][j] = graph[i][j];
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (dist[i][k] != INT_MAX)
            {
                for (int j = 0; j < n; j++)
                {
                    count++;
                    if (dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
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
    floyds(graph, n);

    printf("Shortest distance between all pair of nodes are: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}
void plotter()
{
    srand(time(NULL));
    FILE *f1;
    f1 = fopen("floyds.txt", "w");
    for (int k = 2; k < 12; k++)
    {
        int n = k;
        int graph[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    graph[i][j] = rand();
                }
                else
                {
                    graph[i][j] = 0;
                }
            }
        }
        floyds(graph, n);
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