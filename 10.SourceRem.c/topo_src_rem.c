#include <stdio.h>
#include <stdlib.h>

int isCycle;
int isTester;
int count;
int n;
void topoSort(int graph[n][n])
{
    int sum;
    int indegree[n];
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += graph[j][i];
        }
        indegree[i] = sum;
    }

    int stack[n];
    int top = -1;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            stack[++top] = i;
        }
    }

    if (top == -1)
    {
        isCycle = 1;
        return;
    }
    else
    {
        if (isTester)
        {
            printf("Topological sorting is: \n");
        }
    }

    while (top != -1)
    {
        int u = stack[top--];
        if (isTester)
        {
            printf("%d ", u); // Topological sorted order
        }
        for (int v = 0; v < n; v++)
        {
            count++;
            if (graph[u][v] == 1)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    stack[++top] = v;
                }
            }
        }
    }
}

void tester()
{
    isTester = 1;
    isCycle = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter adjacency matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    topoSort(graph);
    if (isCycle)
    {
        printf("Cycle found, topological sort is not possible\n");
        return;
    }
}

void plotter()
{
    isTester = 0;
    FILE *f1;
    f1 = fopen("topo.txt", "w");
    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int graph[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = 0;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                graph[i][j] = 1;
            }
        }
        count = 0;
        topoSort(graph);
        fprintf(f1, "%d\t%d\n", n, count);
    }
    fclose(f1);
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